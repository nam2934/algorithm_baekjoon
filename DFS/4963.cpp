#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > board;
vector<vector<int> > visited;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int w,h;

void DFS(int y, int x){
    visited[y][x] = true;
    for(int i=0; i<8; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny >= 0 && nx >= 0 && ny < h && nx < w){
            if(!visited[ny][nx] && board[ny][nx] == 1){
                DFS(ny, nx);
            }
        }
    }
}

int main(){
    while(1){
        int result = 0;
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;
        board.clear();
        visited.clear();
        board.assign(h,vector<int>(w, 0));
        visited.assign(h, vector<int>(w, false));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> board[i][j];
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(board[i][j] == 1 && !visited[i][j]){
                    result++;
                    DFS(i,j);
                }
            }
        }
        cout << result << "\n";
    }
}