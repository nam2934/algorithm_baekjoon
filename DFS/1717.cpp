#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,M;
vector<int> adjList[1000001];
int visited[1000001];

bool DFS(int vertex, int find){
    visited[vertex] = true;
    bool flag = false;
    if(vertex == find){
        flag = true;
        return flag;
    }
    for(int i=0; i<adjList[vertex].size(); i++){
        int next = adjList[vertex][i];
        if(!visited[next]){
            return DFS(next, find);
        }
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            adjList[b].push_back(c);
            adjList[c].push_back(b);
        }
        else if(a == 1){
            memset(visited, 0, sizeof(visited));
            if(DFS(b, c)) cout << "YES";
            else cout << "NO" << "\n";        
        }
    }
}