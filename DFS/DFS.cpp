#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

enum MODE{
    STACK_ADJARR,
    RECURSION_ADJARR,
    RECURSION_ARJLIST,
};

vector<vector<int> > adjArr;
vector<vector<int> > adjList;
vector<bool> visited;
stack<int> s;
int V, E;

MODE mode = RECURSION_ARJLIST;

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
0 1 3 2 4

E.g., Graph
0 - 1 
| / |
4 - 3 - 2
************************************/

void DFS(int vertex){
    switch (mode){
    case RECURSION_ADJARR:
        visited[vertex] = true;
        cout << vertex << " ";
        for(int i=0; i<V; i++){
            if(adjArr[vertex][i] == 1 && !visited[i]) DFS(i);
        }
        break;
    case RECURSION_ARJLIST:
        visited[vertex] = true;
        cout << vertex << " ";
        for(auto i : adjList[vertex]){
            if(!visited[i]) DFS(i);
        }
        break;        
    default:
        break;
    }
}

int main(){
    cin >> V >> E;
    int startVertex = 0;
    switch (mode) {
    case STACK_ADJARR:
        adjArr.assign(V, vector<int>(V, 0));
        visited.assign(V, false);
        for(int i=0; i<E; i++){
            int v,w;
            cin >> v >> w;
            adjArr[v][w] = 1;
            adjArr[w][v] = 1;
        }   

        s.push(startVertex);
        visited[startVertex] = true;
        while(!s.empty()){
            int vertex = s.top();
            s.pop();
            cout << vertex << " ";
            for(int i=V-1; i>-0; i--){
                if(adjArr[vertex][i] == 1 && !visited[i]){
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << "\n";
        break;

    case RECURSION_ADJARR:
        adjArr.assign(V, vector<int>(V, 0));
        visited.assign(V, false);
        for(int i=0; i<E; i++){
            int v,w;
            cin >> v >> w;
            adjArr[v][w] = 1;
            adjArr[w][v] = 1;
        }
        DFS(startVertex);
        break;

    case RECURSION_ARJLIST:
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
        DFS(startVertex);
        break;                
    }
}