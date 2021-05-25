#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int cache[100001];
vector<int> weight;
vector<int> value;
int N, K;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    value = vector<int>(N+1);
    weight = vector<int>(N+1);
    for(int i=1; i<=N; i++){
        int w,v;
        cin >> weight[i] >> value[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=K; j>=weight[i]; j--){
            cache[j] = max(cache[j], cache[j-weight[i]] + value[i]);
        }
    }
    cout << cache[K] << "\n";
}