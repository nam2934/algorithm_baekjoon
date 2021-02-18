#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N,M;
vector<vector<int> > board;
vector<vector<bool> > visited;
vector<vector<int> > new_board;

void DFS(int y, int x){
    visited[y][x] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx] && new_board[ny][nx] == 0){
            new_board[ny][nx] = 2;
            DFS(ny,nx);
        }
    }
}

int safe_area_count(){
    int return_value = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(new_board[i][j] == 0) return_value++;
        }
    }
    return return_value;
}

int main(){
    int safe_area_max_count = 0;

    cin >> N >> M;
    board = vector<vector<int> >(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<N*M; i++){
        for(int j=i+1; j<N*M; j++){
            for(int k=j+1; k<N*M; k++){
                if(board[i/M][i%M] == 0 && board[j/M][j%M] == 0 && board[k/M][k%M] == 0){
                    new_board = vector<vector<int> >(N, vector<int>(M));
                    new_board = board;
                    new_board[i/M][i%M] = 1;
                    new_board[j/M][j%M] = 1;
                    new_board[k/M][k%M] = 1;
                    for(int i=0; i<N; i++){
                        for(int j=0; j<M; j++){
                            if(new_board[i][j] == 2){
                                visited = vector<vector<bool> >(N, vector<bool>(M, false));
                                DFS(i,j);
                                visited.clear();
                            }
                        }
                    }
                    int safe_area_cuurent_count = safe_area_count();
                    safe_area_max_count = max(safe_area_max_count, safe_area_cuurent_count);
                    new_board.clear();
                }
            }
        }
    }
    cout << safe_area_max_count;
}