#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
int dx[2] = {-1, 1};
int dy[2] = {1, 1};
vector<vector<int> > board;
int cache[501][501];

int DP(int y, int x){
    if(y == N) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    for(int i=0; i<2; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx >=0 && board[ny][nx] != -1){
            ret = max(ret, DP(ny, nx) + board[y][x]);
        }
    }
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