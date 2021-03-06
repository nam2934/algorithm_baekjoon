#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int N, M;

vector<pair<int, int> > adj[50001];

vector<int> Dijkstra(int src){
    vector<int> dist(N+1, INT_MAX);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cur_dist;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
        adj[v2].push_back(make_pair(v1, w));
    }
    vector<int> result = Dijkstra(1);
    cout << result[N];
}
