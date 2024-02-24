#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define ANSLOG 17

int N,M;
vector<int> parent[ANSLOG+1];
vector<int> visited;
vector<int> depth;
vector<int> adjList[100001];
queue<int> q;

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    for(int i=ANSLOG; i>=0; i--){
        if(depth[b] - depth[a] >= (1 << i)){
            b = parent[i][b];
        }
    }
    if(a == b) return a;
    for(int i=ANSLOG; i>=0; i--){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<=ANSLOG; i++) parent[i] = vector<int>(N+1);
    visited = vector<int>(N+1, 0);
    depth = vector<int>(N+1, 0);
    for(int i=1; i<=N; i++) parent[0][i] = i;
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
                parent[0][next] = cur;
                depth[next] = depth[cur]+1;
                q.push(next);
            }
        }
    }

    for(int i=1; i<=ANSLOG; i++){
        for(int j=1; j<=N; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}