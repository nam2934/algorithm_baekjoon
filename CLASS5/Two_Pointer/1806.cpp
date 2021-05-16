#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> arr;
    int left = 0, right = 0, N, S, length = INT_MAX, sum;
    cin >> N >> S;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    sum = arr[0];
    while(right < N && left <= right){
        if(S > sum){
            right++;
            sum += arr[right];
        }
        else if(S == sum){
            length = min(length , right - left + 1);
            right++;
            sum += arr[right];
        }
        else if(S < sum){
            length = min(length , right - left + 1);
            sum -= arr[left];
            left++;
        }
    }
    if(length == INT_MAX){
        cout << 0;
        return 0;
    }
    cout << length;
}