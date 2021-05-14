#include<iostream>
#include<vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> arr(N);
    vector<int> sum_arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(i == 0) sum_arr[i] = arr[i];
        sum_arr[i] = sum_arr[i-1] + arr[i];
    }
    for(int i=0; i<M; i++){
        int a,b,sum=0;
        cin >> a >> b;
        if(a > 1) sum = sum_arr[b-1] - sum_arr[a-2];
        if(a == 1) sum = sum_arr[b-1];
        cout << sum << "\n";
    }
}