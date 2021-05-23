#include<iostream>
#include<vector>

using namespace std;

int V[10001];
int C[10001];
int K[10001];
int DP[10001];
vector<pair<int,int> > item;

int main(){
    int N,M,result = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> V[i] >> C[i] >> K[i]; 
    }
    for(int i=0; i<N; i++){
        int count = K[i];
        int j;
        for(j=1; j<=K[i]; j*=2){
            if(count - j >= 0){
                item.push_back(make_pair(V[i]*j, C[i]*j));
            }
            count -= j;
        }
        if(count != 0) item.push_back(make_pair(V[i] * (count + j/2), C[i] * (count + j/2)));
    }
    for(int i=0; i<=item.size(); i++){
        for(int j=M; j>=item[i].first; j--){
            DP[j] = max(DP[j], DP[j-item[i].first] + item[i].second);
        }
    }
    cout << DP[M];
}