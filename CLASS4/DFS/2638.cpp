#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > board;
vector<vector<int> > cache;
vector<vector<bool> > visited;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N, M;

void DFS(int y, int x){
    visited[y][x] = true;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < N && nx >= 0 && nx <= M){
            if(!visited[ny][nx]){
                if(board[ny][nx] == 1) cache[ny][nx]++;
                else DFS(ny,nx);
            }
        }
    }
}

bool if_board_clear(){
    bool result = true;
    for(auto i : board){
        for(auto j : i){
            if(j != 0) result = false;
        }
    }
    return result;
}

void change_board(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(cache[i][j] >= 2) board[i][j] = 0;
        }
    }
}

int main(){
    int result_time = 0;
    cin >> N >> M;
    board = vector<vector<int> >(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    while(!if_board_clear()){
        cache = vector<vector<int> >(N, vector<int>(M, 0));
        visited = vector<vector<bool> >(N, vector<bool>(M, false));
        DFS(0,0);
        change_board();
        cache.clear();
        visited.clear();
        result_time++;
    }
    cout << result_time;
}