#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>

using namespace std;

vector<pair<int,int> > adj[801];

int vertex_num, edge_num, pass_v1, pass_v2;

vector<int> Dijkstra(int src){
    vector<int> dist(vertex_num + 1, INT_MAX);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].second;
            int next_dist = adj[here][i].first + cost;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }        
    }
    return dist;
}

int main(){
    cin >> vertex_num >> edge_num;
    for(int i=0; i<edge_num; i++){
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        adj[v1].push_back(make_pair(cost, v2));
        adj[v2].push_back(make_pair(cost, v1));
    }
    cin >> pass_v1 >> pass_v2;
    vector<int> dijk_start = Dijkstra(1);
    vector<int> dijk_v1 = Dijkstra(pass_v1);
    vector<int> dijk_v2 = Dijkstra(pass_v2);
    if(dijk_start[pass_v1] == INT_MAX || dijk_start[pass_v2] == INT_MAX || dijk_v1[pass_v2] == INT_MAX || dijk_v1[vertex_num] == INT_MAX || dijk_v2[pass_v1] == INT_MAX || dijk_v2[vertex_num] == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << min(dijk_start[pass_v1] + dijk_v1[pass_v2] + dijk_v2[vertex_num], dijk_start[pass_v2] + dijk_v2[pass_v1] + dijk_v1[vertex_num]);
}