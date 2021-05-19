#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> A,B,sum_A,sum_B;
    int T,A_size,B_size;
    long long ans = 0;
    cin >> T >> A_size;
    A = vector<int>(A_size);
    for(int i=0; i<A_size; i++) cin >> A[i];
    cin >> B_size;
    B = vector<int>(B_size);
    for(int i=0; i<B_size; i++) cin >> B[i];

    for(int i=0; i<A_size; i++){
        int sum = 0;
        for(int j=i; j<A_size; j++){
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    for(int i=0; i<B_size; i++){
        int sum = 0;
        for(int j=i; j<B_size; j++){
            sum += B[j];
            sum_B.push_back(sum);
        }
    }
    sort(sum_B.begin(), sum_B.end());
    for(auto i : sum_A){
        auto up = upper_bound(sum_B.begin(), sum_B.end(), T-i);
        auto low = lower_bound(sum_B.begin(), sum_B.end(), T-i);
        ans += (up - low);
    }
    cout << ans;
}