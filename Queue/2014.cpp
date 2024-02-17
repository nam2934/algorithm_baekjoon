#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;

    priority_queue<long long, vector<long long>, greater<long long> > pq;
    vector<long long> primes;
    map<long long, bool> m;

    long long top;
    long long maxVal = -1;

    cin >> K >> N;
    for(int i=0; i<K; i++){
        long long n;
        cin >> n;
        primes.push_back(n);
    }
    pq.push(1);
    m[1] = true;

    while(N--){
        top = pq.top();
        pq.pop();
        for(int i=0; i<K; i++){
            long long pushVal = top*primes[i];
            // 이 부분에서 m[pushVal]로 확인하면 메모리 초과. m.count(pushVal)로 확인해야된다.
            if(m.count(pushVal)) continue;
            if(pq.size() > N && maxVal <= pushVal) continue;
            maxVal = max(pushVal, maxVal);
            m[pushVal] = true;
            pq.push(pushVal);
        }
    }
    cout << pq.top();   
}