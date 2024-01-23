#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
vector<int> card;
int cache[1001][1001];

int DP(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return 0;
    
    int& ret = cache[a][b];
    if(ret != -1) return ret;

    if(a<b) return ret = DP(a,b-1);
    ret = max(max(DP(a-b, b) + card[b-1], DP(a,b-1)), DP(a-b, b-1) + card[b-1]);
    return ret;
}

int main(){
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        card.push_back(n);
    }
    cout << DP(N, N);
}