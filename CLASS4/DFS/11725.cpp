#include<iostream>
#include<vector>

using namespace std;

int vertex_num;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> parent;

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<adj[n].size(); i++){
        int there = adj[n][i];
        if(!visited[there]){
            parent[there] = n;
            DFS(there);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> vertex_num;
    adj = vector<vector<int> >(vertex_num);
    visited = vector<bool> (vertex_num, false);
    parent = vector<int>(vertex_num);
    for(int i=0; i<vertex_num-1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2-1);
        adj[v2-1].push_back(v1-1);
    }
    DFS(0);

    for(int i=1; i<vertex_num; i++){
        cout << parent[i]+1 << "\n";
    }
}