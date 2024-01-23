#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int cache[100001];
vector<int> arr;

int DP(int N){
    if(N == 1) return cache[1] = arr[0];
    int& ret = cache[N];
    if(ret != -1) return ret;
    ret = max(DP(N-1) + arr[N-1], arr[N-1]);
    return ret;
}

int main(){
    int N, result = INT_MIN;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    DP(N);
    for(int i=1; i<=N; i++) result = max(cache[i], result);
    cout << result;
}