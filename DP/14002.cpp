#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

int arr[1001];
int cache[1001];
int id[1001];
vector<int> result;
int N;

int main(){
    cin >> N;
    int maxVal = 0;
    int lastid;
    for(int i=0; i<N; i++) cache[i] = 1;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++){
        int maxDP = cache[i];
        for(int j=0; j<=i; j++){
            if(arr[j] < arr[i]){
                if(maxDP < cache[j]+1){
                    id[i] = j;
                    maxDP = cache[j]+1;
                }
            }
        }
        cache[i] = maxDP;
    }
    for(int i=0; i<N; i++){
        maxVal = maxVal < cache[i] ? cache[i] : maxVal;
    }
    cout << maxVal << "\n";
    for(int i=N-1; i>=0; i--){
        if(cache[i] == maxVal){
            lastid = i;
            break;
        }
    }
    while(1){
        result.push_back(arr[lastid]);
        if(cache[lastid] == 1) break;
        lastid = id[lastid];
    }
    reverse(result.begin(), result.end());
    for(auto i : result) cout << i << " ";
}