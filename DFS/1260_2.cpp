#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adjArr;
vector<bool> visited;
int N, M, V;
queue<int> q;

void DFS(int v){
    visited[v] = true;
    cout << v << " ";
    for(int i=1; i<adjArr.size(); i++){
        if(adjArr[v][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    adjArr.assign(N+1, vector<int>(N+1, 0));
    visited.assign(N+1, false);
    for(int i=0; i<M; i++){
        int v, w;
        cin >> v >> w;
        adjArr[v][w] = 1;
        adjArr[w][v] = 1;
    }
    DFS(V);
    cout << "\n";

    // BFS
    visited.assign(N+1, false);
    q.push(V);
    visited[V] = true;
    while(!q.empty()){
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();
        for(int i=1; i<adjArr[vertex].size(); i++){
            if(adjArr[vertex][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << "\n";
}