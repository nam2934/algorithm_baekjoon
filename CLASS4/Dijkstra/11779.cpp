#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>

using namespace std;

vector<pair<int, int> > adj[1001];
vector<int> result;

int vertex_num, edge_num, start_v, end_v;

vector<int> dijkstra(int start){
    vector<int> dist(vertex_num+1, INT_MAX);
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(dist[here] < distance) continue;

        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            int next_dist = adj[here][i].second + distance;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                result[there] = here;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> vertex_num >> edge_num;

    for(int i=0; i<edge_num; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
    }
    cin >> start_v >> end_v;
    result = vector<int>(vertex_num+1);
    vector<int> dist = dijkstra(start_v);
    cout << dist[end_v] << endl;
    int index = end_v;
    stack<int> s;
    while(index){
        s.push(index);
        index = result[index];
    }
    cout << s.size() << endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}