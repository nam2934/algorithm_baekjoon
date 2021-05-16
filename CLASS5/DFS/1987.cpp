#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

bool visited_alpha[26] = {false, };
vector<vector<int> > board; 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int R,C,result = -1;

void DFS(int y, int x, int dist){
    result = max(dist, result);
    visited_alpha[board[y][x]] = true;
    for(int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && ny >= 0 && nx < C && ny < R && !visited_alpha[board[ny][nx]]){
            DFS(ny,nx, dist+1);
        }
    }
    visited_alpha[board[y][x]] = false;
}

int main(){
    cin >> R >> C;
    board = vector<vector<int> >(R, vector<int>(C));
    for(int i=0; i<R; i++){
        string s;
        cin >> s;
        for(int j=0; j<C; j++){
            board[i][j] = (s[j]-65);
        }
    }
    DFS(0,0,1);
    cout << result;
}