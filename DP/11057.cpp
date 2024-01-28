#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[10][1001];

int DP(int b, int c){
    if(b < 0) return 0;
    if(c <= 0) return 0;
    if(b >= 0 && c == 1) return 1;

    int& ret = cache[b][c];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i=0; i<=b; i++) ret += DP(i, c-1) % 10007;
    return ret;
}

int main(){
    int N, result = 0;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<10; i++) result += DP(i,N) % 10007;
    cout << result % 10007;
}