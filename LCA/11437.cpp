#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int N,M;
vector<int> parent;
vector<int> visited;
vector<int> depth;
vector<int> adjList[50001];
queue<int> q;

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    while(depth[a] != depth[b]){
        b = parent[b];
    }
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    parent = vector<int>(N+1);
    visited = vector<int>(N+1, 0);
    depth = vector<int>(N+1, 0);
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    q.push(1);
    visited[1] = true;
    depth[1]++;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<adjList[cur].size(); i++){
            int next = adjList[cur][i];
            if(!visited[next]){
                visited[next] = true;
                parent[next] = cur;
                depth[next] = depth[cur]+1;
                q.push(next);
            }
        }
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}