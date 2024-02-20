#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

int n,m;
int start, dest;

vector<int> dist;
vector<pair<int, int> > adjList[1001];
priority_queue<pair<int, int> > pq;
vector<int> result;
stack<int> st;

void Dijkstra(int start){
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adjList[here].size(); i++){
            int there = adjList[here][i].first;
            int next_dist = adjList[here][i].second + cost;
            if(dist[there] > next_dist){
                dist[there] = next_dist;
                result[there] = here;
                pq.push(make_pair(-next_dist, there));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    result = vector<int>(n+1);
    dist = vector<int>(n+1, INT_MAX);
    for(int i=0; i<m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back(make_pair(e, v));
    }
    for(int i=1; i<=n; i++){
        result[i] = i;
    }
    cin >> start >> dest;
    Dijkstra(start);
    cout << dist[dest] << "\n";
    while(1){
        if(start == dest) break;
        st.push(dest);
        dest = result[dest];
    }
    cout << st.size()+1 << "\n";
    cout << start << " ";
    while(!st.empty()){
        if(st.size() == 1) cout << st.top();
        else cout << st.top() << " ";
        st.pop();
    }
}