#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[1001][1001];

int Combination(int N, int K){
    if(K == 0) return 1;
    if(N == K) return 1;
    int& ret = cache[N][K];
    if(ret != -1) return ret;
    return ret = Combination(N-1, K-1) % 10007 + Combination(N-1, K) % 10007;
}

int main(){
    int n, k;
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << Combination(n, k) % 10007;
}