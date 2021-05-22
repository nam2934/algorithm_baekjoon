#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int company[301][21];
int cache[301][21];
int trace[301][21];
int N,M;

int DP(int n, int comp){
    if(comp == 0) return 0;
    int& ret = cache[n][comp];
    if(ret == -1){
        for(int i=0; i<=n; i++){
            int temp = DP(i, comp-1) + company[n-i][comp];
            if(ret < temp){
                ret = temp;
                trace[n][comp] = n-i;
            }
        }
    }
    return ret;
}

void tracing(int n, int comp){
    if(comp == 0) return;
    int cur = trace[n][comp];
    tracing(n-cur, comp - 1);
    cout << cur << " ";
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        for(int j=1; j<=M; j++){
            cin >> company[n][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << DP(N,M) << endl;
    tracing(N,M);
}