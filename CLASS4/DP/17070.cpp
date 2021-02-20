#include<iostream>
#include<vector>

using namespace std;

int house_size;
vector<vector<int> > board;
int cache[3][17][17];

bool valid_state(int current_state, int y, int x){
    bool result = false;
    if(y >= house_size || x >= house_size) return result;
    if(board[y][x] == 0) result = true;
    if(current_state == 2){
        if(board[y-1][x] == 1 || board[y][x-1] == 1) result = false; 
    }
    return result;
}
int DP(int current_state, int y, int x){
    if(!valid_state(current_state, y, x)) return 0;
    if(y == house_size-1 && x == house_size-1) return 1;
    int& ret = cache[current_state][y][x];
    if(ret == -1){
        if(current_state == 0){
            ret = DP(0, y, x+1) + DP(2, y+1, x+1);
        }
        if(current_state == 1){
            ret = DP(1, y+1, x) + DP(2, y+1, x+1);
        }
        if(current_state == 2){
            ret = DP(0, y, x+1) + DP(1, y+1, x) + DP(2, y+1, x+1);
        }
    }
    return ret;
}
int main(){
    cin >> house_size;
    board = vector<vector<int> >(house_size, vector<int>(house_size));
    for(int i=0; i<3; i++){
        for(int j=0; j<17; j++){
            for(int k=0; k<17; k++){
                cache[i][j][k] = -1;
            }
        }
    }

    for(int i=0; i<house_size; i++){
        for(int j=0; j<house_size; j++){
            cin >> board[i][j];
        }
    }
    cout << DP(0,0,1);
}