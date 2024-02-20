#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int N, M;
vector<pair<int, int> > adjList[1001];
vector<int> visited;
priority_queue<pair<int, int > > pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    
    int result = 0;
    int count = 0;
    cin >> N >> M; 

    visited = vector<int>(N+1, false);

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(c, b));
        adjList[b].push_back(make_pair(c, a));
    }
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        result += cost;
        count++;
        if(count == N) break;
        for(int i=0; i<adjList[cur].size(); i++){
            int next = adjList[cur][i].second;
            int ncost = adjList[cur][i].first;
            if(!visited[next]){
                pq.push(make_pair(-ncost, next));
            }
        }
    }
    cout << result;
}