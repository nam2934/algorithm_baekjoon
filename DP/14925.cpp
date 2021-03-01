#include<iostream>
#include<vector>

using namespace std;

int M, N, result = 0;
vector<vector<int> > board;
vector<vector<int> > cache;

int DP(int y, int x){
    int& ret = cache[y][x];
    if(y == M-1 || x == N-1){        
        return ret = board[y][x];
    }
    if(ret == -100){
        ret = 0;
        if(board[y][x] == -1){
            DP(y,x+1);
            DP(y+1,x);
            DP(y+1,x+1);
            return ret = -1;
        }
        else{
            ret = min(min(DP(y,x+1), DP(y+1,x)),DP(y+1,x+1)) + 1;
            result = max(result, ret);
        }
    }
    return ret;
}

int main(){    
    cin >> M >> N;
    board = vector<vector<int> >(M,vector<int>(N));
    cache = vector<vector<int> >(M,vector<int>(N,-100));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int n;
            cin >> n;
            if(n == 0) board[i][j] = n;
            else board[i][j] = -1;
        }
    }
    DP(0,0);
    bool flag = true;
    for(auto i : board){
        for(auto j : i){
            if(j == 0) flag = false;
        }
    }
    if(flag) cout << 0;
    else cout << result+1;
}