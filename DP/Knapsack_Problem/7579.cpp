#include <iostream> 
#include <algorithm> 
using namespace std; 
int N, M, m[101], c[101], DP[10001]; 

int main(void) { 
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false); 
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> m[i]; 
    for (int i = 0; i < N; i++) cin >> c[i];
    for (int i = 0; i < N; i++) { 
        for (int j = 10000; j >= c[i]; j--) { 
            DP[j] = max(DP[j], DP[j - c[i]] + m[i]);
        } 
    } 
    for(int i=0; i<=10000; i++){
        if(DP[i] >= M){
            cout << i;
            return 0;
        }
    }
}