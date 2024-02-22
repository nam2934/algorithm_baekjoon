#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

long long cache[101][21];
long long arr[101];

long long DP(long long a, long long b){
    if(b > 20 || b < 0) return 0;
    if(a == 1 && b == arr[1]) return 1;
    if(a == 1) return 0;
    long long& ret = cache[a][b];
    if(ret != -1) return ret;
    ret = DP(a-1, b+arr[a]) + DP(a-1, b-arr[a]);
    return ret;
}

int main(){
    long long N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<N; i++){
        cin >> arr[i];
    }
    long long n;
    cin >> n;
    cout << DP(N-1, n);
}