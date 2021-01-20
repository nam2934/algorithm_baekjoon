#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> numArr;
vector<int> picked;
int toPick,N,M;

void pick(vector<int>& picked, int toPick){
    if(toPick == 0){
        for(int i : picked){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back();
    for(int i=0; i<numArr.size(); i++){
        if(numArr[i] >= smallest){
            picked.push_back(numArr[i]);
            pick(picked, toPick-1);
            picked.pop_back();
        }
    }
}

int main(){
    
    vector<int> toPick;
    int duplication[10001] = {false, };
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int number;
        cin >> number;
        if(!duplication[number]){
            numArr.push_back(number);
            duplication[number] = true;
        }
    }
    sort(numArr.begin(), numArr.end());
    pick(picked, M);
}