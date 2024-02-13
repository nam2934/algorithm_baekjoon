#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[100000];
int board[100000][3];
int N;

int DP1(int y){
    if(y == N) return 0;
    int& ret = cache[y];
    if(ret != -1) return ret;
    
    return ret;
}

int main(){
    cin >> N;    
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> board[i][j];
        }
    }    
    memset(cache, -1, sizeof(cache));
    cout << DP1(0) << " ";
    // memset(cache, -1, sizeof(cache));
    // cout << min(min(DP2(0,0), DP2(0,1)), DP2(0,2));
}