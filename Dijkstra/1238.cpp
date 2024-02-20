#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<queue>

using namespace std;

vector<pair<int, int> > adjList1[1001];
vector<pair<int, int> > adjList2[1001];

int N, M, X;

vector<int> Dijkstra(int start, vector<pair<int, int> >* adjList1){
    vector<int> dist(N+1, INT_MAX);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adjList1[here].size(); i++){
            int there = adjList1[here][i].first;
            int next_dist = adjList1[here][i].second + cost;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    vector<int> dist1, dist2;
    int result = -1;
    for(int i=0; i<M; i++){
        int s, e, t;
        cin >> s >> e >> t;
        adjList1[s].push_back(make_pair(e, t));
        adjList2[e].push_back(make_pair(s, t));
    }
    dist1 = Dijkstra(X, adjList1);
    dist2 = Dijkstra(X, adjList2);
    for(int i=1; i<=N; i++){
        result = max(result, dist1[i] + dist2[i]);
    }
    cout << result;
}