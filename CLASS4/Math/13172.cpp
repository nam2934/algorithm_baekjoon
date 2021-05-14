#include<iostream>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

long long pow_mod(int b, int x){
    if(x == 1) return b;
    if(x%2 == 1) return b*pow_mod(b,x-1)%MOD;
    long long t = pow_mod(b, x/2);
    return t*t % MOD;
}

int main(){
    int N;
    long long sum = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        long long gcd_number = __gcd(a,b);
        a /= gcd_number;
        b /= gcd_number;
        sum += b*pow_mod(a,MOD-2)%MOD;
        sum %= MOD;
    }
    cout << sum;
}