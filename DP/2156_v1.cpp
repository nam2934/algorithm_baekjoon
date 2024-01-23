#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> grape;
int cache[3][10001];

int DP(int a, int b){
    if(a == 2 && b == 1) return 0;
    if(b == 1) return grape[0];

    int& ret = cache[a][b];
    if(ret != -1) return ret;

    if(a == 0) ret = max(DP(0, b-1) ,DP(1, b-1) + grape[b-1]);
    if(a == 1) ret = max(DP(0, b-1) ,DP(2, b-1) + grape[b-1]);
    if(a == 2) ret = DP(0, b-1);

    return ret;
}

int main(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        grape.push_back(n);
    }
    cout << DP(0, N);
}