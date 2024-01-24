#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int> > v;
int cache[16];
int N;

int DP(int n){
    if(n >= N) return 0;
    int& ret = cache[n];
    if(ret != -1) return ret;
    if(n+v[n].first > N) return ret = DP(n+1);
    return ret = max(DP(n+v[n].first) + v[n].second, DP(n+1));
}

int main(){    
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    memset(cache, -1, sizeof(cache));
    cout << DP(0);
}