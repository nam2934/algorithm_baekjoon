#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>

using namespace std;

int N,M;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

vector<pair<pair<int, int>, int> > adj[101][101];
vector<vector<int> > board;

void make_graph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(nx >= 0 && ny >= 0 && nx < M && ny < N){
                    adj[i][j].push_back(make_pair(make_pair(ny, nx), board[ny][nx]));
                }
            }
        }
    }
}

vector<vector<int> > dijkstra(int y, int x){
    vector<vector<int> > dist(N, vector<int>(M, INT_MAX));
    dist[y][x] = 0;
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(y, x)));

    while(!pq.empty()){
        int here_y = pq.top().second.first;
        int here_x = pq.top().second.second;
        int cur_dist = -pq.top().first;
        pq.pop();
        for(int i=0; i < adj[here_y][here_x].size(); i++){
            int there_y = adj[here_y][here_x][i].first.first;
            int there_x = adj[here_y][here_x][i].first.second;
            int next_dist = cur_dist + adj[here_y][here_x][i].second;
            if(dist[there_y][there_x] > next_dist){
                dist[there_y][there_x] = next_dist;
                pq.push(make_pair(-next_dist, make_pair(there_y, there_x)));
            }
        }
    }
    return dist;
}

int main(){
    cin >> M >> N; 
    string s;
    getline(cin, s);

    board = vector<vector<int> >(N, vector<int>(M));

    for(int i=0; i<N; i++){
        string s1;
        getline(cin, s1);
        for(int j=0; j<M; j++){
            board[i][j] = s1[j]-'0';
        }
    }
    
    make_graph();
    vector<vector<int> > result = dijkstra(0,0);
    cout << result[N-1][M-1];
}