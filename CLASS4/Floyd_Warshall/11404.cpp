#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > adj;

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;
    adj = vector<vector<int> >(N, vector<int>(N, 987654321));
    for(int i=0; i<M; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1-1][v2-1] = min(adj[v1-1][v2-1], w);
    }
    for(int i=0; i<N; i++) adj[i][i] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
    for(auto i : adj){
        for(auto j : i){
            if(j == 987654321) cout << 0 << " ";
            else cout << j << " ";
        }
        cout << "\n";
    }
}