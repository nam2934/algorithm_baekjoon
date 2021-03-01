#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n1, n2, cnt = 0;
    cin >> n1 >> n2;
    vector<bool> arr(n2-n1+1, true);
    for(long long i=2; i*i<=n2; i++){
        long long here = 0;
        if(n1%(i*i) == 0) here = n1;
        else here = (n1/(i*i)+1)*(i*i);
        for(long long j=0; here + i*i*j <= n2; j++){
            arr[here + i*i*j - n1] = false;
        }
    }
    for(bool i : arr){
        if(i == true) cnt++;
    }
    cout << cnt;
}