#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

#define LGN 17

int N,K;
vector<pair<int, int> > adj[100001];
int parent[LGN+1][100001];
int minValue[LGN+1][100001];
int maxValue[LGN+1][100001];
int depth[100001];
vector<int> visited;
queue<int> q;

pair<int, int> lca(int s, int e){
    int minval = INT_MAX;
    int maxval = -1;
    if(depth[s] > depth[e]) swap(s, e);

    for(int i=LGN; i>=0; i--){
        if(depth[e] - (1 << i) >= depth[s]){
            minval = min(minval, minValue[i][e]);
            maxval = max(maxval, maxValue[i][e]);         
            e = parent[i][e]; 
        }
    }
    if(s == e) return make_pair(minval, maxval);

    for(int i=LGN; i>=0; i--){
        if(parent[i][e] != parent[i][s]){
            minval = min(min(minval, minValue[i][e]), minValue[i][s]);
            maxval = max(max(maxval, maxValue[i][e]), maxValue[i][s]);         
            e = parent[i][e]; 
            s = parent[i][s];
        }
    }    
    minval = min(min(minval, minValue[0][e]), minValue[0][s]);
    maxval = max(max(maxval, maxValue[0][e]), maxValue[0][s]);     
    return make_pair(minval, maxval);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.assign(N+1, false);
    for(int i=1; i<=N; i++) parent[0][i] = i;
    for(int i=0; i<LGN+1; i++){
        for(int j=0; j<100001; j++){
            minValue[i][j] = INT_MAX;
            maxValue[i][j] = INT_MIN;
        }
    }
    for(int i=0; i<N-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    q.push(1);
    visited[1] = true;
    depth[1] = 0;

    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i].first;
            if(!visited[there]){
                visited[there] = true;
                parent[0][there] = here;
                minValue[0][there] = adj[here][i].second;
                maxValue[0][there] = adj[here][i].second;
                depth[there] = depth[here]+1;
                q.push(there);
            }
        }
    }

    for(int i=0; i<LGN; i++){
        for(int j=1; j<=N; j++){
            parent[i+1][j] = parent[i][parent[i][j]];
            minValue[i+1][j] = min(minValue[i][j], minValue[i][parent[i][j]]);
            maxValue[i+1][j] = max(maxValue[i][j], maxValue[i][parent[i][j]]);
        }
    }

    cin >> K;
    for(int i=0; i<K; i++){
        int s, e;
        cin >> s >> e;
        pair<int, int> result = lca(s, e);
        cout << result.first << " " << result.second << "\n";
    }
}