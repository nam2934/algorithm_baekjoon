#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

vector<pair<long, long> > board;
vector<vector<bool> > wire;
vector<pair<int, pair<int, int> > > adj[1001];

int N,W;
double M;

const int INF = 987654321;

void make_graph(){
    for(int i=1; i<=N; i++){
        long x = board[i].first;
        long y = board[i].second;
        for(int j=1; j<=N; j++){
            if(i == j) continue;
            long nx = board[j].first;
            long ny = board[j].second;
            long pow_result = (nx-x)*(nx-x)+(ny-y)*(ny-y);
            double w = sqrt(pow_result);
            if(M >= w){
                if(wire[i][j]) adj[i].push_back(make_pair(j, make_pair(0, 0)));
                else adj[i].push_back(make_pair(j, make_pair(ny-y, nx-x)));
            }
        }
    }
}

vector<double> Dijkstra(int src){
    vector<double> dist(N+1, INF);
    dist[src] = 0.0;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(0.0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        double cur_dist = -pq.top().first;
        pq.pop();
        if(dist[here] < cur_dist) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            double next_dist = sqrt(adj[here][i].second.first*adj[here][i].second.first + adj[here][i].second.second*adj[here][i].second.second);
            next_dist = cur_dist + next_dist;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    cin >> N >> W;
    cin >> M;
    wire = vector<vector<bool> >(N+1, vector<bool>(N+1, false));
    board = vector<pair<long, long> >(N+1);
    for(int i=1; i<=N; i++){
        long x, y;
        cin >> x >> y;
        board[i] = make_pair(x,y);
    }
    for(int i=0; i<W; i++){
        int v1, v2;
        cin >> v1 >> v2;
        wire[v1][v2] = true;
        wire[v2][v1] = true;
    }
    make_graph();
    vector<double> result = Dijkstra(1);
    if(result[N] == INF) cout << -1 << endl;
    else cout << floor(result[N]*1000) << endl;
}