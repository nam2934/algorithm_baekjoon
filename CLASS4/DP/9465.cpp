#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<vector<int> > board;
vector<vector<int> > cache;

int solve(int y, int x){
    if(x == 0) return board[y][0];
    int& ret = cache[y][x];
    if(ret == -1){
        if(x >= 2){
            ret = max(solve(abs(y-1),x-2), solve(abs(y-1),x-1)) + board[y][x];
        }
        else{
            ret = solve(abs(y-1),x-1) + board[y][x];
        }
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    while(testCase--){
        cin >> n;
        board = vector<vector<int> >(2, vector<int>(n));
        cache = vector<vector<int> >(2, vector<int>(n, -1));
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                int num;
                cin >> num;
                board[i][j] = num;
            }
        }
        cout << max(solve(0, n-1),solve(1,n-1)) << "\n";
        board.clear();
        cache.clear();
    }
    

}