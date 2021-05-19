#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

vector<int> direction;
int cache[100001][5][5];

int move(int from, int to){
    if(from == to) return 1;
    switch (from){
    case 0: 
        return 2;
    case 1: 
        if(to == 3) return 4;
        else return 3;
    case 2:
        if(to == 4) return 4;
        else return 3;
    case 3:
        if(to == 1) return 4;
        else return 3;
    case 4:
        if(to == 2) return 4;
        else return 3;
    }
}

int DP(int index,int left, int right){
    if(index == direction.size()) return 0;
    int& ret = cache[index][left][right];
    if(ret == -1){
        return ret = min(move(right, direction[index]) + DP(index+1, direction[index], right), move(left, direction[index]) + DP(index+1, left, direction[index]));
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    int n;
    while(cin >> n){
        if(n == 0) break;
        direction.push_back(n);
    }
    cout << DP(0,0,0);
}