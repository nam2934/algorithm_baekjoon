#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,C,result = 0;
int W[31];
vector<int> g1,g2;

void BF(int s, int e, vector<int>& g, int sum){
    if(s > e){
        g.push_back(sum);
        return;
    }
    BF(s+1,e,g,sum+W[s]);
    BF(s,e,g,sum+W[s]);
}

int main(){
    cin >> N >> C;
    for(int i=0; i<N; i++) cin >> W[i];
    BF(0,N/2,g1,0);
    BF(N/2+1,N,g2,0);
    sort(g2.begin(), g2.end());
    for(int i=0; i<g1.size(); i++){
        if(C-g1[i] > 0) result += upper_bound(g2.begin(), g2.end(), C-g1[i]) - g2.begin();
    }
    cout << result;
}