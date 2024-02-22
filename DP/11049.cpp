#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int cache[501][501];
int N;

pair<int, int> mat[501];

int DP(int l, int r){
    if(l == r) return 0;

    int& ret = cache[l][r];
    if(ret != INT_MAX) return ret;

    for(int i=l; i<r; i++){
        ret = min(ret, DP(l,i) + DP(i+1,r) + mat[l].first*mat[i].second*mat[r].second);
    }   
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int result = INT_MAX;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        mat[i].first = a;
        mat[i].second = b;
    }
    for(int i=0; i<501; i++){
        for(int j=0; j<501; j++){
            cache[i][j] = INT_MAX;
        }
    }
    cout << DP(0, N-1);
}