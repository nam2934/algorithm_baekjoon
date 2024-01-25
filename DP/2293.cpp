#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[10001];
vector<int> nArr;
int n;

int DP(int k){
    cache[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=nArr[i]; j<=k; j++){
            cache[j] += cache[j-nArr[i]];
        }
    }

    return cache[k];
}

int main(){
    int k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int tempInt;
        cin >> tempInt;
        nArr.push_back(tempInt);
    }

    memset(cache, 0, sizeof(cache));
    
    cout << DP(k);
}