#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int cache[3][100001];

int dp(int a, int b){
    if(b == 1) return 1;
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    if(a == 0){
        ret = dp(0,b-1) + dp(1, b-1) + dp(2,b-1);
    }
    if(a == 1){
        ret = dp(2,b-1) + dp(0, b-1);
    }
    if(a == 2){
        ret = dp(0,b-1) + dp(1, b-1);
    }
    ret = ret % 9901;
    return ret;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << (dp(0,N) + dp(1,N) + dp(2,N)) % 9901 << endl;
}