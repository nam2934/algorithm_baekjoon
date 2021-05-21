#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N,T,result=0;
    int study_time[1001];
    int score[1001];
    int DP[101][10001];
    cin >> N >> T;

    for(int i=1; i<=N; i++) cin >> study_time[i] >> score[i];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=T; j++){
            if(j-study_time[i] >= 0) DP[i][j] = max(DP[i-1][j], DP[i-1][j-study_time[i]] + score[i]);
            else DP[i][j] = DP[i-1][j];
            result = max(result,DP[i][j]);
        }
    }
    cout << result;
}