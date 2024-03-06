#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;
string s;
int cache[5001];
int N;

int DP(int n){
    if(n == N) return 0;    
    int& ret = cache[n];
    if(ret != -1) return ret;
    
    ret = 10000000;
    if(s[n] == '0') return ret;

    if(s[n] != '0' && n+3 <= N){
        int a = (s[n]-'0')*100 + (s[n+1]-'0')*10 + (s[n+2]-'0');
        if(a <= 641) ret = min(ret, DP(n+3) + 1);
    }
    if(s[n] != '0' && n+2 <= N){
        ret = min(ret, DP(n+2) + 1);
    }
    if(s[n] != '0' && n+1 <= N){
        ret = min(ret, DP(n+1) + 1);
    }
    return ret;
}

int main(){
    cin >> N;    
    cin >> s;
    memset(cache, -1, sizeof(cache));
    cout << DP(0);
}