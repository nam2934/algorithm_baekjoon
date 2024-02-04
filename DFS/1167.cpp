#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

vector<pair<int, int> > adj[100001];
vector<bool> visited;

int vertex_num;
int far_vertex = 0, dist = 0, result = 0;

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<adj[n].size(); i++){
        int there = adj[n][i].first;
        int cost = adj[n][i].second;
        if(!visited[there]){
            dist += cost;
            if(result < dist){
                far_vertex = there;
                result = dist;
            }
            DFS(there);
            dist -= cost;
        }
    }
}

int main(){
    cin >> vertex_num;
    for(int i=0; i<vertex_num; i++){
        int v1;
        cin >> v1;
        while(true){
            int v2, w;
            cin >> v2;
            if(v2 == -1) break;
            cin >> w;
            adj[v1].push_back(make_pair(v2, w));
            adj[v2].push_back(make_pair(v1, w));
        }
    }
    visited = vector<bool>(vertex_num, false);
    DFS(1);
    visited.clear();
    visited = vector<bool>(vertex_num, false);
    dist = 0;
    result = 0;
    DFS(far_vertex);
    cout << result;
}