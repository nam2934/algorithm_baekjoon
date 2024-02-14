#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

long long cache[100];

long long fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long& ret = cache[n];
    if(ret != -1) return ret;
    return ret = fib(n-1) + fib(n-2);
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << fib(N);
}