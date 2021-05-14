#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

vector<int> liquid;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,left,right,ans,result_left=0,result_right=0;
    ans = INT_MAX;
    cin >> N;
    left = 0;
    right = N-1;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        liquid.push_back(x);
    }
    while(left != right){
        int sum = liquid[left] + liquid[right];
        if(abs(ans) > abs(sum) ){
            ans = sum;
            result_left = liquid[left];
            result_right = liquid[right];
        }
        if(sum < 0) left++;
        if(sum > 0) right--;
        if(sum == 0) break;
    }
    cout << result_left << " " << result_right;
}