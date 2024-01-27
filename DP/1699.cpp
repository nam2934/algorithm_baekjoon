#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[100001];


int DP(int n){
    if(n < 0) return 100000;
    if(n == 0) return 0;

    int& ret = cache[n];
    if(ret != -1) return ret;

    ret = 100000;
    for(int i=1; i*i<=n; i++){
        ret = min(ret, DP(n-i*i)+1);
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << DP(N);
}