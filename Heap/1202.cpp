#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int N,K;
vector<pair<int, int> > jewelry;
vector<int> bag;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    jewelry = vector<pair<int, int> >(N);
    long long maxValue = 0;

    bag = vector<int>(K);
    for(int i=0; i<N; i++){
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for(int i=0; i<K; i++){
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end());
    sort(jewelry.begin(), jewelry.end());
    int j = 0;
    for(int i=0; i<bag.size(); i++){
        while(j < jewelry.size() && jewelry[j].first <= bag[i]){
            pq.push(jewelry[j++].second);
        }
        if(!pq.empty()){
            maxValue += pq.top();
            pq.pop();            
        }
    }
    cout << maxValue;
}