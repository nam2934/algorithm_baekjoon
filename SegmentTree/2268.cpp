#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int N,M;
long long arr[1000001];
long long segTree[4000001];

long long query(int now, int start, int end, int left, int right){
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return segTree[now];
    int next = now*2;
    int mid = (start + end)/2;
    return query(next, start, mid, left, right) + query(next+1, mid+1, end, left, right);
}

void update(int now, int start, int end, int idx, long long value){
    if(idx < start || idx > end) return;
    segTree[now] += value;
    if(start == end) return;
    int next = now*2;
    int mid = (start + end)/2;
    update(next, start, mid, idx, value);
    update(next+1, mid+1, end, idx, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int mode, a, b;
        cin >> mode >> a >> b;
        if(mode == 0){
            if(a > b) swap(a, b);
            cout << query(1, 1, N, a, b) << "\n";
        }
        if(mode == 1){
            long long diff = (long long)b - arr[a];
            arr[a] = b;
            update(1, 1, N, a, (long long)diff);
        }
    }
}