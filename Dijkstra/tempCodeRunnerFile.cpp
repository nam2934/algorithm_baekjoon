#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>
#define DBL_MAX 1.7976931348623158e+308

using namespace std;

vector<pair<int, int> > board;
vector<vector<bool> > wire;
vector<pair<int, double> > adj[1001];

int N,W;
double M;

void make_graph(){
    for(int i=1; i<N; i++){
        int x = board[i].first;
        int y = board[i].second;
        for(int j=i; j<=N; j++){
            if(i == j) continue;
            int nx = board[j].first;
            int ny = board[j].second;
            double w = sqrt((nx-x)*(nx-x)+(ny-y)*(ny-y));
            if(w <= M){
                if(wire[i][j]) adj[i].push_back(make_pair(j, 0));
                else adj[i].push_back(make_pair(j, w));
            }
        }
    }
}

vector<double> Dijkstra(int src){
    vector<double> dist(N+1, DBL_MAX);
    dist[src] = 0;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        double cur_dist = -pq.top().first;
        pq.pop();
        if(dist[here] < cur_dist) continue;
        dist[here] = cur_dist;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            double next_dist = cur_dist + adj[here][i].second;
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
    board = vector<pair<int, int> >(N+1);
    for(int i=1; i<=N; i++){
        int x, y;
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
    cout << (long long)result[N]*1000 << endl;
}

