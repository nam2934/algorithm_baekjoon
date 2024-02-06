#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[51];

int fibonacci(int n){
    if(n < 2){
        return 1;
    }
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (fibonacci(n-2)%1000000007 + fibonacci(n-1)%1000000007 + 1)%1000000007;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << fibonacci(N)%1000000007;
}