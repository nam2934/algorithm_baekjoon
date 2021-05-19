#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, left = 0, right = 0, sum = 0, ans = 0;
    cin >> N;
    vector<bool> prime_check(N+1, true);
    vector<int> prime;
    for(int i=2; i*i<=N; i++){
        if(!prime_check[i]) continue;
        for(int j=i+i; j<=N; j+=i){
            prime_check[j] = false;
        }
    }
    for(int i=2; i<=N; i++){
        if(prime_check[i]){
            prime.push_back(i);
        }
    }
    while(right <= prime.size()){
        if(sum < N){
            if(right == prime.size()) break;
            sum += prime[right];
            right++;
            continue;
        }
        if(sum == N){
            ans++;
        }
        sum -= prime[left];
        left++;
    }
    cout << ans;
}