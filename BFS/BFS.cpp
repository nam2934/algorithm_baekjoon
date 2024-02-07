#include<iostream>
#include<vector>
#include<queue>

using namespace std;


enum MODE{
    ADJARR,
    ADJLIST
};

vector<vector<int> > adjArr;
vector<vector<int> > adjList;
vector<bool> visited;
queue<int> q;
int V, E;

// Change below parameters.
MODE mode = ADJLIST;
int startVertex = 0;

/************************************
Initialize the graph as shown below.
Input - 
    first line : Number of vertex - V, Number of edge - E
    second ~ second + E - 1 line : vertex1 - v, vertex2 - w

E.g., Input
5 6
0 1
0 4
1 4
1 3
4 3
3 2

- Output : visit smaller vertex
0 1 4 3 2

E.g., Graph
0 - 1 
| / |
4 - 3 - 2
************************************/

int main(){
    cin >> V >> E;
    switch (mode) {
    case ADJARR:
        adjArr.assign(V, vector<int>(V, 0));
        visited.assign(V, false);
        for(int i=0; i<E; i++){
            int v,w;
            cin >> v >> w;
            adjArr[v][w] = 1;
            adjArr[w][v] = 1;
        }   
        q.push(startVertex);
        visited[startVertex] = true;
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";
            for(int i=0; i<V; i++){
                if(adjArr[vertex][i] == 1 && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        break;

    case ADJLIST:
        adjList = vector<vector<int> >(V);
        visited.assign(V, false);
        for(int i=0; i<E; i++){
            int v,w;
            cin >> v >> w;
            adjList[v].push_back(w);
            adjList[w].push_back(v);
        }
        for(int i=0; i<V; i++){
            sort(adjList[i].begin(), adjList[i].end());
        }
        q.push(startVertex);
        visited[startVertex] = true;
        while(!q.empty()){
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();
            for(auto i : adjList[vertex]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        break;
    }   
}