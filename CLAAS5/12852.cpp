#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> parent;

int main(){
    int n;
    cin >> n;   
    adj = vector<vector<int> >(n+1);
    parent = vector<int>(n+1, 0);
    visited = vector<bool>(n+1, false);
    parent[n] = n;
    for(int i=1; i<=n; i++){
        if(i%3 == 0) adj[i].push_back(i/3);
        if(i%2 == 0) adj[i].push_back(i/2);
        if(i>1) adj[i].push_back(i-1);
    }
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int here = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(here == 1) cout << dist << endl;
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i];
            if(!visited[there]){
                q.push(make_pair(there, dist+1));
                visited[there] = true;
                parent[there] = here;
            }
        }
    }
    int V = 1;
    vector<int> result;
    result.push_back(1);
    while(parent[V] != V){
        V = parent[V];
        result.push_back(V);
    }
    for(int i=result.size()-1; i>=0; i--) cout << result[i] << " ";
}