#include<iostream>
#include<vector>
using namespace std;

int R,C,T;
vector<vector<int> > board;
vector<vector<int> > diffusion_board;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int air_cleaner_bottom_x, air_cleaner_bottom_y;

void diffuse(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int diffuse_direct = 0;
            for(int k=0; k<4; k++){
                int nx = j+dx[k];
                int ny = i+dy[k];
                if(nx >= 0 && ny >= 0 && nx < C && ny < R && board[ny][nx] != -1 && board[i][j] != -1){
                    diffuse_direct++;
                    diffusion_board[ny][nx] += board[i][j] / 5;
                }
            }
            diffusion_board[i][j] -= (board[i][j] / 5)*diffuse_direct;
        }
    }
}

void sum_board(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            board[i][j] += diffusion_board[i][j];
        }
    }
}

void clean_top(){
    int air_cleaner_top_y = air_cleaner_bottom_y - 1;
    int air_cleaner_top_x = air_cleaner_bottom_x;
    for(int i=air_cleaner_top_y-2; i>=0; i--){
        board[i+1][0] = board[i][0];
    }
    for(int i=0; i<C-1; i++){
        board[0][i] = board[0][i+1];
    }
    for(int i=0; i<=air_cleaner_top_y-1; i++){
        board[i][C-1] = board[i+1][C-1];
    }
    for(int i=C-1; i>1; i--){
        board[air_cleaner_top_y][i] = board[air_cleaner_top_y][i-1];
    }
    board[air_cleaner_top_y][1] = 0;
}

void clean_bottom(){
    for(int i=air_cleaner_bottom_y+2; i<R; i++){
        board[i-1][0] = board[i][0];
    }
    for(int i=0; i<C-1; i++){
        board[R-1][i] = board[R-1][i+1];
    }
    for(int i=R-2; i>=air_cleaner_bottom_y; i--){
        board[i+1][C-1] = board[i][C-1];
    }
    for(int i=C-1; i>1; i--){
        board[air_cleaner_bottom_y][i] = board[air_cleaner_bottom_y][i-1];
    }
    board[air_cleaner_bottom_y][1] = 0;
}

int result(){
    int count = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(board[i][j] != -1) count += board[i][j];
        }
    }
    return count;
}

int main(){
    cin >> R >> C >> T;
    board = vector<vector<int> >(R, vector<int>(C));    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
            if(board[i][j] == -1){
                air_cleaner_bottom_y = i;
                air_cleaner_bottom_x = j;
            }
        }
    }
    while(T--){
        diffusion_board.clear();
        diffusion_board = vector<vector<int> >(R, vector<int>(C, 0));
        diffuse();
        sum_board();
        clean_top();
        clean_bottom();
    }
    cout << result();
}