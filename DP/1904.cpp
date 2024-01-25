#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[1000001];

int DP(int N){
    if(N == 1) return 1;
    if(N == 2) return 2;

    int& ret = cache[N];

    if(ret != -1) return ret;

    return ret = DP(N-1) % 15746 + DP(N-2) % 15746;
}

int main(){
    int N; 
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << DP(N) % 15746;
}