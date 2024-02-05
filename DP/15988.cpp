#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[1000001];

int DP(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    int& ret = cache[n];
	
	if(ret != -1) return ret;
	
    ret = ((DP(n-1) %1000000009 + DP(n-2) %1000000009) % 1000000009 + DP(n-3) %1000000009) % 1000000009;
    return ret %1000000009;
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));	
    while(N--){
        int n;
        cin >> n;
        cout << DP(n) << "\n";
    }
}