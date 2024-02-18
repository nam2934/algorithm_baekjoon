#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<cmath>

using namespace std;

int N;
vector<int> hist;
vector<int> segTree;

int query(int now, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return segTree[now];
    int next= now*2;
    int mid = (start + end) / 2;
    int leftIndex = query(next, start, mid, left, right);
    int rightIndex = query(next+1, mid+1, end, left, right);
    return hist[leftIndex] > hist[rightIndex] ? rightIndex : leftIndex;
}

void update(int now, int start, int end, int idx){
    if(idx < start || idx > end) return;
    segTree[now] = hist[segTree[now]] > hist[idx] ? idx : segTree[now]; 
    if(start == end) return;
    int next = now*2;
    int mid = (start + end) / 2;
    update(next, start, mid, idx);
    update(next+1, mid+1, end, idx);
};

long long find(int left, int right){
    if(left > right) return 0;
    int minValueIndex = query(1, 1, N, left, right);
    long long result = (long long)(right-left+1)*(long long)hist[minValueIndex];
    return max(result, max(find(left, minValueIndex-1), find(minValueIndex+1, right)));
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    hist = vector<int>(N+1, INT_MAX);
    segTree = vector<int>(4*N, 0);
    for(int i=1; i<=N; i++){
        cin >> hist[i]; 
        update(1, 1, N, i);
    }
    cout << find(1, N);
}