#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,Q;
vector<long long> segTree;
vector<long long> arr;

long long query(int now, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return segTree[now];
    if(start == end) segTree[now];
    int mid = (start + end) / 2;
    return query(now*2, start, mid, left, right) + query(now*2+1, mid+1, end, left, right);
}

void update(int now, int start, int end, int idx, long long value){
    if(idx < start || idx > end) return;
    segTree[now] += value;
    if(start == end) return;
    int mid = (start + end)/2;
    update(now*2, start, mid, idx, value);
    update(now*2+1, mid+1, end, idx, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    arr = vector<long long>(N+1, 0);
    segTree = vector<long long>(N*4, 0);
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    while(Q--){
        int x, y, a;
        long long b;
        cin >> x >> y >> a >> b;
        if(y < x){
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
        cout << query(1, 1, N, x, y) << "\n";
        long long diff = b-arr[a];
        arr[a] = b;
        update(1, 1, N, a, diff);
    }
}