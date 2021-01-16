#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> numArr;

void pick(int N, vector<int>& picked, int toPick){
    if(toPick == 0){
        for(int i : picked){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    int smallest;
    if(picked.empty()){
        smallest = 0;
    }
    else{
        for(int i=0; i<N; i++){
            if(picked.back() == numArr[i]){
                smallest = i;
            }
        }
    }
    for(int i = smallest; i < N; i++){
        picked.push_back(numArr[i]);
        pick(N,picked,toPick-1);
        picked.pop_back();
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,M;
    vector<int> picked;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        numArr.push_back(num);
    }
    sort(numArr.begin(), numArr.end());
    pick(N, picked, M);
}