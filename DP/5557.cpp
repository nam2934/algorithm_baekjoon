#include<iostream>
#include<cstring>

using namespace std;

long long cache[21][101];
int number[101];
int result_num, N;

long long DP(int sum, int n){
    if(n == N-2){
        if(result_num == sum) return 1;
        else return 0;
    }
    long long& ret = cache[sum][n];
    if(ret != -1) return ret;
    ret = 0;
    if(sum - number[n+1] >= 0) ret += DP(sum-number[n+1], n+1);
    if(sum + number[n+1] <= 20) ret += DP(sum+number[n+1], n+1);
    return ret;
}

int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++) cin >> number[i];
    result_num = number[N-1];
    cout << DP(number[0], 0);
}