#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<pair<int, int> > adj[1001];

int vertex_num, edge_num;

vector<int> dijkstra(int start){
    vector<int> dist(vertex_num+1, INT_MAX);
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(0, start));
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
    int start_vertex, end_vertex;
    cin >> vertex_num >> edge_num;
    for(int i=0; i<edge_num; i++){
        int v1,v2,weight;
        cin >> v1 >> v2 >> weight;
        adj[v1].push_back(make_pair(v2, weight));
    }
    cin >> start_vertex >> end_vertex;
    vector<int> result = dijkstra(start_vertex);
    cout << result[end_vertex];
}