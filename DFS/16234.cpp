#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

vector<vector<int> > board;
vector<vector<int> > visited;
vector<vector<int> > checkPrev;
vector<pair<int, int> > unions;
int N, L, R;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void DFS(int y, int x){
    unions.emplace_back(y, x);
    visited[y][x] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
            int cond = abs(board[y][x] - board[ny][nx]);
            if(cond >= L && cond <= R && !visited[ny][nx]){
                DFS(ny,nx);
            }
        }
    }
    
}


void makeNewBoard(){
    int sum_ = 0;
    int size_ =  unions.size();
    int newValue;
    for(int i=0; i<size_; i++){
        sum_ += board[unions[i].first][unions[i].second];
    }
    newValue = int(sum_ / size_);
    for(int i=0; i<size_; i++){
        board[unions[i].first][unions[i].second] = newValue;
    }
}

int main(){
    cin >> N >> L >> R;
    int result = 0;
    board.assign(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }       
    while(1){
        int cnt = 0;
        bool flag = false;
        visited.assign(N, vector<int>(N, false));
        checkPrev.assign(N, vector<int>(N, false)); 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j]){
                    DFS(i, j);   
                    if(unions.size() > 1){
                        flag = true;
                        makeNewBoard();
                    }                               
                    unions.clear();       
                }               
            }
        }
        if(!flag) break;
        result++;
    }
    cout << result;
}
