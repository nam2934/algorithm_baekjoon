#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
const int MAX = 1000001;
int cache[MAX];

int DP(int n){
    if(n == 1) return 0;
    int& ret = cache[n];
    if(ret != MAX) return ret;
    if(n % 3 == 0) ret = min(ret, DP(n/3)+1);
    if(n % 2 == 0) ret = min(ret, DP(n/2)+1);
    ret = min(ret, DP(n-1)+1);
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<MAX; i++) cache[i] = MAX;
    cout << DP(N);
}