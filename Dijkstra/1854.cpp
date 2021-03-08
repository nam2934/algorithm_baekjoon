#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,k;
const int INF = 1987654321;
vector<pair<int, int> > adj[1001];

vector<vector<int> > Dijkstra(int src){
    vector<vector<int> > dist(k+1, vector<int>(n+1, INF));
    vector<int> visited(n+1, 0);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(visited[here] >= k) continue;
        visited[here]++;
        dist[visited[here]][here] = cur_dist;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cur_dist;
            pq.push(make_pair(-next_dist, there));
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
    }
    vector<vector<int> > result = Dijkstra(1);
    for(int i=1; i<=n; i++){
        if(result[k][i] == INF) cout << -1 << "\n";
        else cout << result[k][i] << "\n";  
    }
    
}