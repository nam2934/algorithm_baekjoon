#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

vector<int> times;
vector<int> cache;
bool adj[1001][1001];

int N,K,W;

int DP(int n){
    int& ret = cache[n];
    if(ret == -1){
        int time = 0;
        for(int i=1; i<=N; i++){
            if(adj[i][n]){
                time = max(time, DP(i));
            }
        }
        return ret = time + times[n];
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> N >> K;
        times.clear();
        cache.clear();
        memset(adj, false, sizeof(adj));
        times = vector<int>(N+1);
        cache = vector<int>(N+1, -1);
        for(int i=1; i<=N; i++) cin >> times[i];
        for(int i=0; i<K; i++){
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1][v2] = true;
        }
        cin >> W;
        cout << DP(W) << "\n";
    }
}