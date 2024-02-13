#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int discovered[100001];
queue<pair<int, int> > Q;
int N,K;

void pushQ(int nx, pair<int, int> qTop){
    if(nx <= 100000 && nx >= 0){
        if(!discovered[nx]){
            discovered[nx] = true;
            Q.push(make_pair(qTop.first+1, nx));
        };
    }    
}

int main(){
    cin >> N >> K;
    memset(discovered, false, sizeof(discovered));
    Q.push(make_pair(0, N));
    discovered[N] = true;
    while(!Q.empty()){
        pair<int, int> qTop = Q.front();
        Q.pop();
        if(qTop.second == K){
            cout << qTop.first;
            return 0;
        }
        int nx = qTop.second + 1;
        pushQ(nx, qTop);
        nx = qTop.second - 1;
        pushQ(nx, qTop);
        nx = qTop.second*2;
        pushQ(nx, qTop);
    }
    
}