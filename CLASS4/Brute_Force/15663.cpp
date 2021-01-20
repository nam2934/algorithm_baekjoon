#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> numArr;
vector<int> picked;
vector<bool> visited;
int toPick,N,M;

void pick(vector<int>& picked, int toPick){
    if(toPick == 0){
        for(int i : picked){
            cout << i << " ";
        }
        cout << "\n";
    }
    int duplication[10001] = {false, };
    for(int i=0; i<N; i++){
        if(!visited[i] && !duplication[numArr[i]]){
            picked.push_back(numArr[i]);
            visited[i] = true;
            duplication[numArr[i]] = true;
            pick(picked, toPick-1);
            picked.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    
    vector<int> toPick;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int number;
        cin >> number;
        numArr.push_back(number);
    }
    visited = vector<bool>(N, false);
    sort(numArr.begin(), numArr.end());
    pick(picked, M);
}