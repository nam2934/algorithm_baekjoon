#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

long cache[100000][3];
long board[100000][3];
long N;

long DP1(long y, long x){
    if(y == N) return 0;
    long& ret = cache[y][x];
    if(ret != -1) return ret;
    if(x == 0) ret = max(DP1(y+1, 0), DP1(y+1, 1)) + board[y][x];
    if(x == 1) ret = max(max(DP1(y+1, 0), DP1(y+1, 1)), DP1(y+1, 2)) + board[y][x];
    if(x == 2) ret = max(DP1(y+1, 1), DP1(y+1, 2)) + board[y][x];
    return ret;
}

long DP2(long y, long x){
    if(y == N) return 0;
    long& ret = cache[y][x];
    if(ret != -1) return ret;
    if(x == 0) ret = min(DP2(y+1, 0), DP2(y+1, 1)) + board[y][x];
    if(x == 1) ret = min(min(DP2(y+1, 0), DP2(y+1, 1)), DP2(y+1, 2)) + board[y][x];
    if(x == 2) ret = min(DP2(y+1, 1), DP2(y+1, 2)) + board[y][x];
    return ret;
}

long main(){
    cin >> N;    
    for(long i=0; i<N; i++){
        for(long j=0; j<3; j++) cin >> board[i][j];
    }
    memset(cache, -1, sizeof(cache));
    cout << max(max(DP1(0,0), DP1(0,1)), DP1(0,2)) << " ";
    memset(cache, -1, sizeof(cache));
    cout << min(min(DP2(0,0), DP2(0,1)), DP2(0,2));
}