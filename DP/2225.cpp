#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,K,cache[201][201];

int DP(int n, int k){
    if(k == 1) return 1;
    int& ret = cache[n][k];
    if(ret == -1){
        ret = 0;
        for(int i=0; i<=n; i++){
            ret = (ret + DP(i, k-1)) % 1000000000;
        }
    }
    return ret;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    cout << DP(N,K);
}