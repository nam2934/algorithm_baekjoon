#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int INF = 1987654321;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n;
vector<vector<int> > board;

vector<vector<int> > Dijkstra(int y, int x){
    vector<vector<int> > dist(n, vector<int>(n, INF));
    dist[y][x] = 0;
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(y,x)));
    while(!pq.empty()){
        int here_y = pq.top().second.first;
        int here_x = pq.top().second.second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(dist[here_y][here_x] < cur_dist) continue;
        for(int i=0; i<4; i++){
            int ny = here_y + dy[i];
            int nx = here_x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < n){
                int next_dist;
                if(board[ny][nx] - '0' == 0) next_dist = cur_dist+1;
                else next_dist = cur_dist;
                if(dist[ny][nx] > next_dist){
                    dist[ny][nx] = next_dist;
                    pq.push(make_pair(-next_dist, make_pair(ny, nx)));
                }
            }
        }
    }
    return dist;
}

int main(){
    cin >> n;
    board = vector<vector<int> >(n, vector<int>(n));
    string s;
    getline(cin, s);
    for(int i=0; i<n; i++){
        getline(cin, s);
        for(int j=0; j<n; j++){
            board[i][j] = s[j];
        }
    }
    vector<vector<int> > result = Dijkstra(0,0);
    cout << result[n-1][n-1];
}