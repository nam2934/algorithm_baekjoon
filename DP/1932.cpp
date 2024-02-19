#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
int dx[2] = {0, 1};
int dy[2] = {1, 1};
vector<vector<int> > board;
int cache[501][501];

int DP(int y, int x){
    if(x == N || y == N) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = max(DP(y+1, x), DP(y+1, x+1)) + board[y][x];
    
    return ret;
}

int main(){
    cin >> N;
    board.assign(N, vector<int>(N, -1));
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            cin >> board[i][j];
        }
    }
    cout << DP(0,0);
}