#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m,t;
const int INF = 1987654321;
vector<pair<int, int> > adj[2001];

vector<int> Dijkstra(int src){
    vector<int> dist(n+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        int here = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(dist[here] < cur_dist) continue;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + cur_dist;
            if(next_dist < dist[there]){
                dist[there] = next_dist;
                pq.push(make_pair(-next_dist, there));
            }
        } 
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int test_case;
    cin >> test_case;
    while(test_case--){
        int start, trans_v1, trans_v2;
        vector<int> des_arr;
        cin >> n >> m >> t;
        cin >> start >> trans_v1 >> trans_v2;
        for(int i=0; i<m; i++){
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v1].push_back(make_pair(v2, w));
            adj[v2].push_back(make_pair(v1, w));
        }
        for(int i=0; i<t; i++){
            int des;
            cin >> des;
            des_arr.push_back(des);
        }
        vector<int> start_dist = Dijkstra(start);
        vector<int> trans_v1_dist = Dijkstra(trans_v1);
        vector<int> trans_v2_dist = Dijkstra(trans_v2);
        vector<int> result;
        for(int i=0; i<t; i++){
            if(start_dist[des_arr[i]] >= min(trans_v1_dist[start]+trans_v2_dist[des_arr[i]], trans_v1_dist[des_arr[i]]+trans_v2_dist[start]) + trans_v1_dist[trans_v2]){
                result.push_back(des_arr[i]);
            }
        }
        sort(result.begin(), result.end());
        for(auto i : result) cout << i << " ";
        cout << "\n";
        for(int i=0; i<=2000; i++) adj[i].clear();
    }
}