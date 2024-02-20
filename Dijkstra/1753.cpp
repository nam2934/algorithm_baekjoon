#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int V,E,start;
vector<pair<int, int> > adjList[20001];
priority_queue<pair<int, int> > pq;
vector<int> dist;

void Dijkstra(int start){
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adjList[here].size(); i++){
            int nextDist = adjList[here][i].second + cost;
            int there = adjList[here][i].first;
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> start;
    dist = vector<int>(V+1, INT_MAX);
    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v, w));
    }
    Dijkstra(start);
    for(int i=1; i<=V; i++){
        if(dist[i] == INT_MAX) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}