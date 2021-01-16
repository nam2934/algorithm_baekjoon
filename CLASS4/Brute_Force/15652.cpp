#include<iostream>
#include<vector>
using namespace std;

void pick(int N, vector<int>& v, int toPick){
    if(toPick == 0){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    int smallest = v.empty() ? 1 : v.back();
    for(int i = smallest; i<=N; i++){
        v.push_back(i);
        pick(N, v, toPick-1);
        v.pop_back();
    }
}

int main(){
    int N,M;
    vector<int> v;
    cin >> N >> M;
    pick(N,v,M);
}