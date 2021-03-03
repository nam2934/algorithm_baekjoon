#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<queue>

using namespace std;

vector<int> item;
vector<pair<int,int> > adj[100];
vector<int> shortes_dist;
int vertex_num, edge_num, max_dist, result = 0;

vector<int> Dijkstra(int src){
    vector<int> dist(vertex_num, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        for(auto iter : adj[here]){
            int there = iter.first;
            int next_dist = iter.second + cur_dist;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    cin >> vertex_num >> max_dist >> edge_num;
    item = vector<int>(vertex_num);
    for(int i=0; i<vertex_num; i++){
        cin >> item[i];
    }
    for(int i=0; i<edge_num; i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        adj[v1-1].push_back(make_pair(v2-1, w));
        adj[v2-1].push_back(make_pair(v1-1, w));
    }
    for(int i=0; i<vertex_num; i++){
        int sum = 0;
        shortes_dist = Dijkstra(i);
        for(int j = 0; j<vertex_num; j++){
            if(shortes_dist[j] <= max_dist) sum += item[j];
        }
        result = max(result, sum);
        shortes_dist.clear();
    }
    cout << result;
}