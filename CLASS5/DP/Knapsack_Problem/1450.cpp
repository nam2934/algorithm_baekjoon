#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long result = 0;
int N,C;
long long W[31];
vector<long long> g1,g2;

void BF(int s, int e, vector<long long>& g, long long sum){
    if(s > e){
        g.push_back(sum);
        return;
    }
    BF(s+1,e,g,sum);
    BF(s+1,e,g,sum+W[s]);
}

int main(){
    cin >> N >> C;
    for(int i=0; i<N; i++) cin >> W[i];
    BF(0,N/2,g1,0);
    BF(N/2+1,N-1,g2,0);
    sort(g2.begin(), g2.end());
    for(int i=0; i<g1.size(); i++){
        result += (upper_bound(g2.begin(), g2.end(), C-g1[i]) - g2.begin());
    }
    cout << result;
}