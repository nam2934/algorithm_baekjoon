#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int cache[100001];

int dp(int a){
    if(a == 0) return 1;
    if(a == 1) return 3;
    int& ret = cache[a];
    if(ret != -1) return ret;
    ret = dp(a-1)*2+dp(a-2);
    ret = ret % 9901;
    return ret;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << dp(N) << endl;
}