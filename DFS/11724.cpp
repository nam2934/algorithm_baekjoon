#include<iostream>
#include<vector>
using namespace std;

//인접리스트 define
vector<vector<int> > adj;
//방문여부 define
vector<bool> visited;

void dfs(int here){
    visited[here] = true;
    for(int i=0; i<adj[here].size(); i++){
        int there = adj[here][i];
        if(!visited[there]){
            dfs(there);
        }
    }
}

int main(){
    int count = 0;
    //number of vertex and edge
    int number_of_vertex, number_of_edge;
    cin >> number_of_vertex >> number_of_edge;

    //assign adj list
    adj = vector<vector<int> >(number_of_vertex);
    //assign visited 
    visited = vector<bool>(number_of_vertex, false);

    for(int i=0; i<number_of_edge; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2-1);
        adj[v2-1].push_back(v1-1);
    }

    for(int i=0; i<number_of_vertex; i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }

    cout << count;
}