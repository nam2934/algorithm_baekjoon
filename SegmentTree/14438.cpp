#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int N, M;
int segTree[400001];

int query(int now, int start, int end, int left, int right){
    if(start > right || end < left) return INT_MAX;
    if(left <= start && end <= right) return segTree[now];
    int next = now*2;
    int mid = (start + end) / 2;
    return min(query(next, start, mid, left, right), query(next+1, mid+1, end, left, right));
}

void update(int now, int start, int end, int idx, int value){
    if(idx < start || idx > end) return;
    segTree[now] = value;
    if(start == end) return;
    int next = now*2;
    int mid = (start + end) / 2;
    update(next, start, mid, idx, value);
    update(next+1, mid+1, end, idx, value);
    segTree[now] = min(segTree[next], segTree[next+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<400001; i++) segTree[i] = INT_MAX;
    cin >> N;
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        update(1, 1, N, i, n);
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 1, N, b, c);
        } else if(a == 2){
            cout << query(1, 1, N, b, c) << "\n";
        }
    }
}