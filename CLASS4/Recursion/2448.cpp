#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

char base[3][6] = {"  *  ", " * * ", "*****"};
vector<vector<char> > board;

void solve(int n, int y, int x){
    if(n == 1){
        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                board[y+i][x+j] = base[i][j];
            }
        }
        return;
    }
    solve(n/2, y+3*n/2, x);
    solve(n/2, y, x+3*n/2);
    solve(n/2, y+3*n/2, x+3*n);
}

int main(){
    int N;
    cin >> N;
    board = vector<vector<char> >(N, vector<char>(2*N-1));
    solve(N/3, 0, 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            if(board[i][j] == '*') cout << '*';
            else cout << " ";
        }
        cout << endl;
    }
}