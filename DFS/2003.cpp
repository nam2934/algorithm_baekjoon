#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,M;
int result = 0;
int temp = 0;
int arrN[10001];

void DFS(int n){
    temp += arrN[n];
    if(temp == M){
        result++;
        return;
    }
    else if(temp > M){
        return;
    }
    if(n+1 < N){
        DFS(n+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arrN[i];
    }
    for(int i=0; i<N; i++){
        temp = 0;
        DFS(i);
    }
    cout << result;
}