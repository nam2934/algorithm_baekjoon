#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

int cache[501][501];
int sum[501];
int K;
int file_arr[501];
const int MAX = 987654321;

int DP(int left, int right){
    if(left >= right) return 0;
    if(left + 1 == right) return file_arr[left] + file_arr[right];
    int& ret = cache[left][right];
    if(ret != -1) return ret;
    ret = MAX;
    for(int i=left; i<right; i++){
        ret = min(ret, DP(left, i) + DP(i+1, right) + sum[right] - sum[left-1]);
    }
    return ret;
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> K;
        memset(cache, -1, sizeof(cache));
        memset(sum, 0, sizeof(sum));
        for(int i=1; i<=K; i++){
            cin >> file_arr[i];
            if(i == 0) sum[i] = file_arr[i];
            else sum[i] = sum[i-1] + file_arr[i];
        }
        cout << DP(1,K) << "\n";
    }
}