#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool row[9][9] = {false, };
bool col[9][9] = {false, };
bool square[9][9] = {false, };
int board[9][9];

void DFS(int n){
    int y = n/9;
    int x = n%9;
    if(n == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    if(board[y][x] != 0) DFS(n+1);
    else{
        for(int i=1; i<=9; i++){
            if(!row[y][i] && !col[x][i] && !square[x/3 + (y/3)*3][i]){
                row[y][i] = true;
                col[x][i] = true;
                square[x/3 + (y/3)*3][i] = true;
                board[y][x] = i;
                DFS(n+1);
                row[y][i] = false;
                col[x][i] = false;
                square[x/3 + (y/3)*3][i] = false;
                board[y][x] = 0;
            }
        }
    }
}

int main(){
    for(int i=0; i<9; i++){
        string s;
        cin >> s;
        for(int j=0; j<9; j++){
            board[i][j] = s[j]-'0';
            if(board[i][j] != 0){                
                row[i][s[j]-'0'] = true;
                col[j][s[j]-'0'] = true;
                square[j/3 + (i/3)*3][s[j]-'0'] = true;
            }
        }
    }
    DFS(0);
}