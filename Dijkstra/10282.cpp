#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int> > adj[10001];

const int INF = 1987654321;
int computer;
vector<int> Dijkstra(int start){
    vector<int> dist(computer+1, INF);
    
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        for(int i=0; i<10001; i++) adj[i].clear();
        int dependency, start_v;
        cin >> computer >> dependency >> start_v;
        for(int i=0; i<dependency; i++){
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v2].push_back(make_pair(v1, w));
        }
        vector<int> dist = Dijkstra(start_v);
    }
}