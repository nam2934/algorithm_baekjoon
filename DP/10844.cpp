#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[10][101];

int DP(int a, int b){
    if(b == 1 && a == 0) return 0;
    if(b == 1) return 1;

    int& ret = cache[a][b];
    if(ret != - 1)  return ret;

    if(a == 0) return ret = DP(1, b-1);
    if(a == 9) return ret = DP(8, b-1);
    return ret = (DP(a-1, b-1) + DP(a+1, b-1)) % 1000000000;
}

int main(){
    int N, result = 0;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<10; i++) result = (result + DP(i, N)) % 1000000000;
    cout << result;
}