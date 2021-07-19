#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

int n, money;
double m, each_money;;
int C[5001], P[5001], DP[10001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(true){
        cin >> n >> m;
        money = (int)(m*100+0.5);
        memset(C,0,sizeof(C));
        memset(P,0,sizeof(P));
        memset(DP,0,sizeof(DP));
        if(n == 0 && m == 0.00) break;
        for(int i=0; i<n; i++){
            cin >> C[i] >> each_money;
            P[i] = (int)(each_money*100+0.5);
        }
        for(int i=0; i<n; i++){
            for(int j=P[i]; j<=money; j++){
                DP[j] = max(DP[j-P[i]]+C[i],DP[j]);
            }
        }
        cout << DP[money] << "\n";
    }
}