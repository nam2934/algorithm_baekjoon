#include<iostream>
#include<cstring>
using namespace std;

int cache[501][501], board[501][501], N, M;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int DP(int y, int x){
    if(y == N-1 && x == M-1) return 1;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < M && ny < N){
            if(board[ny][nx] < board[y][x]){
                ret += DP(ny, nx);
            }
        }
    }
    return ret;
}

int main(){
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    cout << DP(0,0);
}