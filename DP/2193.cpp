#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

long long cache[2][91];

long long DP(int a, int b){
    if(a == 0 && b == 1) return 0;
    if(b == 1) return 1;
    long long& ret = cache[a][b];
    if(ret != -1) return ret;
    if(a == 0) ret = DP(1, b-1) + DP(0, b-1);
    if(a == 1) ret = DP(0, b-1);
    return ret;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << DP(0, N) + DP(1, N);
}