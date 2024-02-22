#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int board[1001][1001];
int cache[1001][1001];

int DP(int y, int x){
    if(y == 0 || x == 0) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret  = 0;
    if(board[y][x] == 0){
        DP(y-1, x);
        DP(y, x-1);
        return 0;
    }
    else{
        ret = 1;
        ret += min(min(DP(y-1, x), DP(y, x-1)), DP(y-1, x-1));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, result = 0;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=1; j<=M; j++){
            board[i][j] = s[j-1]-'0';
        }
    }
    memset(cache, -1, sizeof(cache));
    DP(N, M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            result = max(result, cache[i][j]);
        }
    }
    cout << result*result;
}