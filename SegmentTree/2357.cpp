#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

vector<pair<int, int> > segTree;

int N,M;

pair<int, int> query(int now, int start, int end, int left, int right){
    if(end < left || start > right) return make_pair(-1, INT_MAX);
    if(left <= start && end <= right) return make_pair(segTree[now].first, segTree[now].second);
    int next = now*2;
    int mid = (start + end) / 2;
    pair<int, int> leftresult = query(next, start, mid, left, right);
    pair<int, int> rightresult = query(next+1, mid+1, end, left, right);
    return make_pair(max(leftresult.first, rightresult.first), min(leftresult.second, rightresult.second));
}

void update(int now, int start, int end, int idx, int value){
    if(idx < start || idx > end) return;
    segTree[now].first = max(value, segTree[now].first);
    segTree[now].second = min(value, segTree[now].second);
    if(start == end) return;
    int mid = (start + end) / 2;
    update(now*2, start, mid, idx, value);
    update(now*2+1, mid+1, end, idx, value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    segTree = vector<pair<int, int> >(N*4, make_pair(-1, INT_MAX));
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        update(1, 1, N, i, n);
    }
    for(int i=0; i<M; i++){
        int left, right;
        cin >> left >> right;
        pair<int, int> result = query(1, 1, N, left, right);
        cout << result.second << " " << result.first << "\n";
    }
}