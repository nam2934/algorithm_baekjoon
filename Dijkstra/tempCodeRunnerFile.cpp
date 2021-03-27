#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > adj[10001];

const int INF = 1987654321;
int computer;
vector<int> Dijkstra(int start){
    vector<int> dist(computer+1);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(cur_dist > dist[here]) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cur_dist;
            if(next_dist < dist[there]){
                pq.push(make_pair(-next_dist, there));
                dist[there] = next_dist;
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while(testcase--){
        for(int i=0; i<10001; i++) adj[i].clear();
        int dependency, start_v;
        cin >> computer >> dependency >> start_v;
        for(int i=0; i<dependency; i++){
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v2].push_back(make_pair(v1, w));
        }
        vector<int> dist = Dijkstra(start_v);
        int result_time = 0;
        int result_count = 0;
        for(int i=0; i<dist.size(); i++){
            if(dist[i] == INF) continue;
            result_count++;
            if(dist[i] > result_time){
                result_time = dist[i];
            }
        }
        cout << result_count << " " << result_time << "\n";
    }
}