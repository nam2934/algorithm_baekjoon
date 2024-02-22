#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int W, H;
long long cache[101][101][2][2];

long long DP(int w, int h, int d1, int d2){
    if(w > W || h > H) return 0;
    if(w == W && h == H) return 1;
    long long& ret = cache[w][h][d1][d2];
    if(ret != -1) return ret;
    if(d2 == 0){
        if(d1 == 0){
            return ret = (DP(w+1, h, 0, 0) % 100000  + DP(w, h+1, 0, 1) % 100000) % 100000 ;
        }
        else if(d1 == 1){
            return ret = DP(w+1, h, 0, 0) % 100000 ;
        }
    }
    if(d2 == 1){
        if(d1 == 0){
            return ret = DP(w, h+1, 1, 1) % 100000 ;
        }
        else if(d1 == 1){
            return ret = (DP(w+1, h, 1, 0) % 100000  + DP(w, h+1, 1, 1) % 100000) % 100000  ;
        }
    }    
}

int main(){
    cin >> W >> H;
    memset(cache, -1, sizeof(cache));
    cout << (DP(1,1,0,1) % 100000 + DP(1,1,1,0) % 100000) % 100000;
}