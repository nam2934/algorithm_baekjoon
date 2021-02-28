#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

vector<vector<int> > board;
vector<vector<bool> > visited[2];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N, M;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    string s;
    cin >> N >> M;
    getline(cin, s);
    board = vector<vector<int> >(N+1, vector<int>(M+1));
    for(int i=0; i<2; i++) visited[i] = vector<vector<bool> >(N+1, vector<bool>(M+1, false));

    for(int i=1; i<=N; i++){
        getline(cin, s);
        for(int j=1; j<=M; j++){
            board[i][j] = (s[j-1] -'0');
        }
    }
    
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(1,1), make_pair(1, 0)));
    visited[0][1][1] = true;

    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second.first;
        int destroy = q.front().second.second;
        q.pop();

        if( x == M && y == N ){
            cout << dist;
            return 0;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= M && ny <= N){
                if(board[ny][nx] == 1 && destroy == 0){
                    q.push(make_pair(make_pair(ny, nx), make_pair(dist+1, destroy+1)));
                }
                else if(board[ny][nx] == 0 && !visited[destroy][ny][nx]){
                    q.push(make_pair(make_pair(ny, nx), make_pair(dist+1, destroy)));
                    visited[destroy][ny][nx] = true;
                }
            }
        }
    }
    cout << -1;
}
