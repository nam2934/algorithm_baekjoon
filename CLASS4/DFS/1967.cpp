#include<iostream>
#include<vector>
using namespace std;

int vertex_num, result = 0, dist;

vector<pair<int,int> > adj[10001];
vector<bool> visited;


vector<int> make_leaf(){
    vector<int> leaf_node;
    for(int i=1; i<=vertex_num; i++){
        if(adj[i].size() == 1) leaf_node.push_back(i);
    }
    return leaf_node;
}

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<adj[n].size(); i++){
        int there = adj[n][i].first;
        int cost = adj[n][i].second;
        if(!visited[there]){
            dist += cost;
            if(dist > result) result = dist;
            DFS(there);
            dist -= cost;
        }
    }
}

int main(){
    cin >> vertex_num;
    for(int i=0; i<vertex_num-1; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
        adj[v2].push_back(make_pair(v1, w));
   }
    vector<int> leaf_node = make_leaf();

    for(int i : leaf_node){
        visited = vector<bool>(vertex_num+1, false);
        dist = 0;
        DFS(i);
        visited.clear();
    }
    cout << result;
}