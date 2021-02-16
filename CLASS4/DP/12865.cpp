#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int cache[102][100002];
vector<int> weight;
vector<int> value;
int N, K;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    value = vector<int>(N+1);
    weight = vector<int>(N+1);
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            cache[i][j] = 0;
        }
    }
    for(int i=1; i<=N; i++){
        int w,v;
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j >= weight[i]) cache[i][j] = max(cache[i-1][j], cache[i-1][j-weight[i]]+value[i]);
            else cache[i][j] = cache[i-1][j];
        }
    }
    cout << cache[N][K] << "\n";
}