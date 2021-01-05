#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MAX = 1000001;
int cache[MAX];

int DP(int n){
    cache[1] = 0;
	for(int i=2; i<=n; i++){
        cache[i] = cache[i-1]+1;
        if(i % 2 == 0){
            cache[i] = min(cache[i], cache[i/2]+1);
        }
        if(i % 3 == 0){
            cache[i] = min(cache[i], cache[i/3]+1);
        }
    }
    return cache[n];
}

int main(){
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << DP(n);
}