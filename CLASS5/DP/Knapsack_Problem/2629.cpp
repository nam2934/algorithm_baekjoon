#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

bool cache[31][15001];
int S_W[31], W[8];
int S_N, W_N;

void DP(int i, int w){
    if(i > S_N || cache[i][w]) return;
    bool& ret = cache[i][w];
    ret = true;
    DP(i+1, w + S_W[i]);
    DP(i+1,w);
    DP(i+1, abs(w - S_W[i]));
    return;
}

int main(){
    cin >> S_N;
    for(int i=0; i<S_N; i++) cin >> S_W[i];
    DP(0,0);
    cin >> W_N;
    for(int i=0; i<W_N; i++) cin >> W[i];
    for(int i = 0; i<W_N; i++){
        if(W[i] > 15000) cout << "N" << " ";
        else if(cache[S_N][W[i]]) cout << "Y" << " ";
        else cout << "N" << " ";
    }
}