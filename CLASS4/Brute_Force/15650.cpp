#include<iostream>
#include<vector>
using namespace std;

void pick(int N, vector<int>& picked, int toPick){
    if(toPick == 0){
        for(int i : picked){
            cout << i+1 << " ";
        }
        cout << endl;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int i = smallest; i<N; i++){
        picked.push_back(i);
        pick(N, picked, toPick-1);
        picked.pop_back();
    }
}

int main(){
    int N,M;
    vector<int> v;
    cin >> N >> M;
    pick(N,v,M);
}