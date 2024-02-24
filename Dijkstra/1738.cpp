#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<stack>
#include<algorithm>

using namespace std;

int n,m;
vector<pair<int, int> > adj[101];
vector<int> parent;
vector<int> dist;
stack<int> st;
vector<int> result;

void DFS(int start, vector<int>& visited){
    visited[start] = true;
    for(int i=0; i<adj[start].size(); i++){
        if(!visited[adj[start][i].first]){
            DFS(adj[start][i].first, visited);
        }
    }
}

bool BellmanFord(int start){
    dist.assign(n+1, INT_MAX);
    parent.assign(n+1, INT_MAX);
    dist[start] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<adj[j].size(); k++){
                if(dist[j] == INT_MAX) continue;
                if(dist[adj[j][k].first] > dist[j] + adj[j][k].second){
                    if(i == n){
                        vector<int> visited(n+1, 0);
                        DFS(adj[j][k].first, visited);                   
                        if(visited[n]) return true;
                    }
                    dist[adj[j][k].first] = dist[j] + adj[j][k].second;
                    parent[adj[j][k].first] = j;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, -w));
    }
    if(BellmanFord(1)){
        cout << -1;
        return 0;
    }
    else{
        if(dist[n] == INT_MAX){
            cout << -1;
            return 0;
        }
        else{
            while(1){
                result.push_back(n);
                if(n == 1) break;
                n = parent[n];
            }            
        }
    }
    reverse(result.begin(), result.end());
    for(int i : result){
        cout << i << " ";
    }
}