#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int N, M;
vector<int> arr;
vector<int> segTree;

int query(int now, int start, int end, int left, int right){
    if(start > right || end < left) return INT_MAX;
    if(left <= start && end <= right) return segTree[now];
    int mid = (start + end) / 2;
    int next = now*2;
    return min( query(next, start, mid, left, right), query(next+1, mid+1, end, left, right) );
}

void update(int now, int start, int end, int idx, int value){
    if(idx < start || idx > end) return;
    segTree[now] = min(value, segTree[now]);
    if(start == end) return;
    int mid = (start+end)/2;
    int next = now*2;
    update(next, start, mid, idx, value);
    update(next+1, mid+1, end, idx, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    arr = vector<int>(N+1);
    segTree = vector<int>(4*N+1, INT_MAX);
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    for(int i=0; i<M; i++){
        int left, right;
        cin >> left >> right;
        cout << query(1, 1, N, left, right) << "\n";
    }
}