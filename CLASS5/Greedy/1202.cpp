#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int, int> > gem;
vector<int> bag;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,K,index=0;
    long long sum = 0;
    priority_queue<int> pq;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int M,V;
        cin >> M >> V;
        gem.push_back(make_pair(M, V));
    }
    for(int i=0; i<K; i++){
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());
    for(int i=0; i<K; i++){
        while(gem[index].first <= bag[i] && index < N){
            pq.push(gem[index++].second);
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << "\n";
}