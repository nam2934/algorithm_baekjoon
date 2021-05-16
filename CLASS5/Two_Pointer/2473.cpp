#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

vector<int> arr;

int main(){
    int N;
    long long diff = 9223372036854775807;
    vector<long long> result;
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<N-2; i++){
        int left = i+1, right = N-1, comp = arr[i];
        while(left != right){
            long long sum = arr[left] + arr[right];
            if(abs(sum + comp) < diff){
                diff = abs(sum + comp);
                result.clear();
                result.push_back(comp);
                result.push_back(arr[left]);
                result.push_back(arr[right]);
            }
            if(sum + comp < 0) left++;
            if(sum + comp > 0) right--;
            if(sum + comp == 0) break;
        }
    }
    sort(result.begin(), result.end());
    for(auto i : result) cout << i << " ";
}