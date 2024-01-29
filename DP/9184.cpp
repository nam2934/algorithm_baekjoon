#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[102][102][102];

int DP(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    int& ret = cache[a+50][b+50][c+50];
    if(ret != -1) return ret;
    if(a>20 || b>20 || c>20) return ret = DP(20, 20, 20);
    if(a<b && b<c) return ret = DP(a,b,c-1) + DP(a,b-1,c-1) - DP(a,b-1,c);
    return ret = DP(a-1,b,c)+ DP(a-1, b-1, c) + DP(a-1, b, c-1) - DP(a-1, b-1, c-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    memset(cache, -1, sizeof(cache));
    while(cin >> a >> b >> c){
        if(a == -1 && b == -1 && c == -1) return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << DP(a,b,c) << endl;
    }
}