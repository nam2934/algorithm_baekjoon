#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[1001][1001];
vector<vector<int> > maze;
int N,M;

void initMaze(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cache[i][j] = -1;
        }
    }
}

int DP(int r, int c){
    if(r == N-1 && c == M-1) return maze[r][c];

    int& ret = cache[r][c];
    if(ret != -1) return ret;

    ret = maze[r][c] + max(max(DP(r,c+1), DP(r+1,c)), DP(r+1,c+1));
    return ret;
}

int main(){
    cin >> N >> M;
    maze = vector<vector<int> >(N, vector<int>(M));    
    initMaze();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> maze[i][j];
        }
    }
    cout << DP(0,0);
}