#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int N,M;
vector<pair<int, int> > adjList[501];
long long dist[501];

bool Bellmanford(int start){
    for(int i=1; i<=N; i++){
        dist[i] = __LONG_LONG_MAX__;
    }
    dist[start] = 0;
    for(int i=0; i<N-1; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<adjList[j].size(); k++){
                if(dist[j] == __LONG_LONG_MAX__) continue;
                if(dist[adjList[j][k].first] > dist[j] + adjList[j][k].second){
                    dist[adjList[j][k].first] = dist[j] + adjList[j][k].second;
                }
            }
        }
    }
    bool isNegativeCycle = false;

    for(int i=1; i<=N; i++){
        for(int j=0; j<adjList[i].size(); j++){
            if(dist[i] == __LONG_LONG_MAX__) continue;
            if(dist[adjList[i][j].first] > dist[i] + adjList[i][j].second){
                isNegativeCycle = true;
                break;
            }
        }
    }
    return isNegativeCycle;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back(make_pair(e, v));
    }
    if(!Bellmanford(1)){
        for(int i=2; i<=N; i++){
            if(dist[i] == __LONG_LONG_MAX__) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
    else{
        cout << -1 << "\n";
    }
}