#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<pair<int, int> > adj[1000];
vector<int> result;
int N,M,X,MAX=0;

vector<int> Dijkstra(int src){
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = cur_dist + adj[here][i].second;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    cin >> N >> M >> X;
    result = vector<int>(N, 0);
    for(int i=0; i<M; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1-1].push_back(make_pair(v2-1, w));
    }
    result = Dijkstra(X-1);
    for(int i=0; i<N; i++){
        vector<int> each_result = Dijkstra(i);
        result[i] += each_result[X-1];
    }
    for(int i : result){
        if(i > MAX) MAX = i;
    }
    cout << MAX;
}