#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int vertex_num, edge_num;
const int INF = 1987654321;
vector<pair<int, int> > adj[1001];
vector<int> parent;

void Dijkstra(int start){
    parent = vector<int>(vertex_num+1);
    vector<int> dist(vertex_num+1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(cur_dist > dist[here]) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cur_dist;
            if(next_dist < dist[there]){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
                parent[there] = here;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> vertex_num >> edge_num;
    for(int i=0; i<edge_num; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
        adj[v2].push_back(make_pair(v1, w));
    }
    Dijkstra(1);
    cout << vertex_num-1 << "\n";
    for(int i=2; i<=vertex_num; i++){
        cout << parent[i] << " " << i << "\n";
    }
}