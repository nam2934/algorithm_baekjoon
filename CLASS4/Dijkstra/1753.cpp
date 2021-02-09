#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

vector<pair<int,int> > adj[20001];

int vertex_num, edge_num;

vector<int> Dijkstra(int start){
    vector<int> dist(vertex_num+1, INT_MAX);
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cost;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int start_vertex;
    cin >> vertex_num >> edge_num >> start_vertex;
    for(int i=0; i<edge_num; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }
    vector<int> result = Dijkstra(start_vertex);
    for(int i=1; i<=vertex_num; i++){
        if(result[i] == INT_MAX) cout << "INF" << "\n";
        else cout << result[i] << "\n";
    }
}