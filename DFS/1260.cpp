#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<bool> discovered;

void dfs(int here){
    visited[here] = true;
    cout << here+1 << " ";
    for(int i=0; i<adj[here].size(); i++){
        int there = adj[here][i];
        if(!visited[there]){
            dfs(there);
        }
    }
}

int main(){
    int vertex_count, edge_count, start_vertex;
    cin >> vertex_count >> edge_count >> start_vertex;
    adj = vector<vector<int> >(vertex_count);
    visited = vector<bool>(vertex_count, false);
    discovered = vector<bool>(vertex_count, false);
    for(int i=0; i<edge_count; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2-1);
        adj[v2-1].push_back(v1-1);
    }

    for(int i=0; i<vertex_count; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(start_vertex-1);
    cout << endl;

    queue<int> q;
    discovered[start_vertex-1] = true;
    q.push(start_vertex-1);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        cout << here + 1 << " ";
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i];
            if(!discovered[there]){
                q.push(there);
                discovered[there] = true;
            }
        }
    }
}