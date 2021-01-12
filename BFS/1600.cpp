#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > board;
vector<vector<vector<bool> > > visited;
int dx_4[4] = {1, -1, 0, 0};
int dy_4[4] = {0, 0, 1, -1};
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int main(){    
    int k, w, h;
    cin >> k >> w >> h;
    board = vector<vector<int> >(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> board[i][j];
        }
    }
    
    visited = vector<vector<vector<bool> > >(h, vector<vector<bool> >(w, vector<bool>(31, false)));

    queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push(make_pair( make_pair(0,0), make_pair(0,0) ) );
    visited[0][0][0] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int k_cnt = q.front().second.second;
        q.pop();

        if(x == w-1 && y == h-1){
            cout << cnt << endl;
            return 0;
        }
        if(k_cnt < k){
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < w && ny < h){
                    if(board[ny][nx] == 0 && !visited[ny][nx][k_cnt+1]){
                        visited[ny][nx][k_cnt+1] = true;
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, k_cnt+1)));
                    }
                }
            }            
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx_4[i];
            int ny = y + dy_4[i];
            if(nx >= 0 && ny >= 0 && nx < w && ny < h){
                if(board[ny][nx] == 0 && !visited[ny][nx][k_cnt]){
                    visited[ny][nx][k_cnt] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, k_cnt)));
                }
            }
        }
    }
    cout << -1;
}