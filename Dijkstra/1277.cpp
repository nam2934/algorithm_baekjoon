#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

vector<pair<int, int> > board;
vector<pair<int, double> > adj[1001];

int N,W;
double M;

double get_dist(int x1, int x2, int y1, int y2){
    return sqrt(pow(x1-x2 , 2)+pow(y1-y2, 2));
}

void make_graph(){
    for(int i=1; i<N; i++){
        for(int j=i; j<=N; j++){
            int x = board[i].first;
            int y = board[i].second;
            int nx = board[j].first;
            int ny = board[j].second;
            double w = get_dist(x,nx,y,ny);
            if(w <= M){
                adj[i].push_back(make_pair(j, w));
                adj[j].push_back(make_pair(i, w));
            }
        }
    }
}

vector<double> Dijkstra(int src){
    vector<double> dist(N+1, 1.79769e+308);
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
    board = vector<pair<int, int> >(N+1);
    for(int i=1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        board[i] = make_pair(x,y);
    }
    for(int i=0; i<W; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(make_pair(v2,0));
        adj[v2].push_back(make_pair(v1,0));
    }
    make_graph();
    vector<double> result = Dijkstra(1);
    cout << (long long)(result[N]*1000);
}

