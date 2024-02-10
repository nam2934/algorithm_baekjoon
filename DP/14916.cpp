#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
int cache[100001];

int DP(int n){
    if(n == 0) return 0;
    else if(n < 0) return 100000;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = min(DP(n-2) + 1, DP(n-5) + 1);
}

int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int result = DP(N);
    if(result < 100000) cout << result;
    else cout << -1;
}