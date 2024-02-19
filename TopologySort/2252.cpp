#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M;

vector<int> adjList[32001];
int visited[32001];
int indegree[32001];
vector<int> ordered;
vector<int> start;

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<adjList[n].size(); i++){
        if(!visited[adjList[n][i]]){
            DFS(adjList[n][i]);
        }
    }
    ordered.push_back(n);
}

void TopologySort(){
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0) start.push_back(i);
    }

    for(auto i : start) DFS(i);
    reverse(ordered.begin(), ordered.end());
}

int main(){
    cin >> N >> M;
    memset(visited, 0, sizeof(visited));
    memset(indegree, 0, sizeof(indegree));
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        indegree[b]++;
    }
    TopologySort();
    for(auto i : ordered) cout << i << " ";
}