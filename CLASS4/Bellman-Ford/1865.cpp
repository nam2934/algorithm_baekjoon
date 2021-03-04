#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int INF = 123456789;
int main(){
    int testcase;
    vector<pair<int,int> > adj[501];
    vector<int> upper;
    cin >> testcase;
    while(testcase--){
        upper.clear();
        for(int i=0; i<501; i++) adj[i].clear();
        
        int N, M, W;
        cin >> N >> M >> W;
        
        for(int i=0; i<M; i++){
            int S, E, T;
            cin >> S >> E >> T;
            adj[S].push_back(make_pair(E,T));
            adj[E].push_back(make_pair(S,T));
        }

        for(int i=0; i<W; i++){
            int S, E, T;
            cin >> S >> E >> T;
            adj[S].push_back(make_pair(E,-T));
        }

        upper = vector<int>(N+1, INF);
        upper[1] = 0;
        bool is_minus_cycle = false;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int k=0; k<adj[j].size(); k++){
                    int there = adj[j][k].first;
                    int cost = adj[j][k].second;
                    if(upper[there] > upper[j] + cost){
                        upper[there] = upper[j] + cost;
                        if(i == N) is_minus_cycle = true;
                    }
                }
            }
        }
        if(is_minus_cycle) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}