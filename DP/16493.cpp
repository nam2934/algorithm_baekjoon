#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int cache[201][21];

int N, M;
vector<pair<int, int> > v;

int DP(int n, int m){
    if(n == 0) return 0;
    if(m < 0) return 0;

    int& ret = cache[n][m];
    if(ret != -1) return ret;
    if(n-v[m].first < 0) return DP(n, m-1);
    return ret = max(ret, max(DP(n-v[m].first, m-1) + v[m].second, DP(n, m-1)));
}   
int main(){
    cin >> N >> M;
    v = vector<pair<int, int> >(M);
    for(int i=0; i<M; i++){
        cin >> v[i].first >> v[i].second;
    }
    memset(cache, -1, sizeof(cache));
    cout << DP(N, M-1);
}