#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[301][2];
int arr[301];

int DP(int s, int c){
    if(s <= 0) return 0;
    int& ret = cache[s][c];
    if(ret != -1) return ret;
    if(c == 1) ret = DP(s-2, 0) + arr[s];
    else{
        ret = max(DP(s-1, c+1), DP(s-2, 0)) + arr[s];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));   
    cout << DP(N, 0);
}