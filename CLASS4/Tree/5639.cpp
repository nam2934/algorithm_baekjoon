#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;

void postorder(int start, int end){
    if(start >= end) return;
    int upperIndex = distance(arr.begin() ,upper_bound(arr.begin()+start+1, arr.begin()+end, arr[start]));
    postorder(start+1, upperIndex);
    postorder(upperIndex, end);
    cout << arr[start] << endl;
}

int main(){
    int size = 0;
    int n;
    while(cin >> n){
        size++;
        arr.push_back(n);
    }
    postorder(0, arr.size());
}