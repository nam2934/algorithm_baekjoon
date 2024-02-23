#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<queue>

using namespace std;

int N,M,S,D;

vector<pair<int, int> > adj[501];
vector<int> del[501];
vector<int> dist;
priority_queue<pair<int, int> > pq;

void delEdge(int start){
   queue<int> q;
   vector<int> visited;
   visited.assign(N, 0);
   
   q.push(start);
   while(!q.empty()){
        int here = q.front();
        q.pop();
        if(visited[here]) continue;
        visited[here] = 1;
        for(int i=0; i<del[here].size(); i++){
            int there = del[here][i];
            for(int j=0; j<adj[there].size(); j++){
                if(adj[there][j].first == here){
                    adj[there][j].second = -1;
                }                  
                q.push(there);                  
            }
        }
    }
}

void Dijkstra(int start){
    dist.assign(N, INT_MAX);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++){
            if(adj[here][i].second == -1){
                continue;
            }
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;
            if(dist[there] == nextDist){
                del[there].push_back(here);
            }
            if(dist[there] > nextDist){
                del[there].clear();
                pq.push(make_pair(-nextDist, there));
                dist[there] = nextDist;
                del[there].push_back(here);
            }
        }
    }
}

int main(){
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> S >> D;
        
        dist.assign(N, INT_MAX);
        for(int i=0; i<501; i++){
            adj[i].clear();
            del[i].clear();
        }

        for(int i=0; i<M; i++){
            int u,v,p;
            cin >> u >> v >> p;
            adj[u].push_back(make_pair(v, p));
        }
        Dijkstra(S);  
        delEdge(D);
        Dijkstra(S);
        if(dist[D] == INT_MAX) cout << -1 << "\n";
        else cout << dist[D] << "\n";
    }
}