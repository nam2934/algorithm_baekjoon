#include<iostream>
#include<vector>
#include<cmath>

const int MAX = 987654321;

int cache[1001][3];
int cost[1001][3];

using namespace std;

int main(){
    int N,result;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }
    result = MAX;
    for(int i=0; i<3; i++){
        cache[0][0] = MAX;
        cache[0][1] = MAX;
        cache[0][2] = MAX;
        cache[0][i] = cost[0][i];
        for(int j=1; j<N; j++){
            cache[j][0] = min(cache[j-1][1], cache[j-1][2]) + cost[j][0];
            cache[j][1] = min(cache[j-1][0], cache[j-1][2]) + cost[j][1];
            cache[j][2] = min(cache[j-1][0], cache[j-1][1]) + cost[j][2];
        }
        for(int j=0; j<3; j++){
            if(i == j) continue;
            result = min(result, cache[N-1][j]);
        }
    }
    cout << result;
}