#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int N,M;
int parent[1000001];
int Rank[1000001];

int getParent(int n){
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

void Union(int b, int c){
    int newB = getParent(b);
    int newC = getParent(c);
    if(newB == newC) return;
    if(Rank[newB] < Rank[newC]){
        parent[newB] = newC;
    }
    else{
        parent[newC] = newB;
    }
    if(Rank[newB] == Rank[newC]){
        Rank[newC]++;
    }
    
}

int Find(int b, int c){
    int parentB = getParent(b);
    int parentC = getParent(c);
    return parentB == parentC;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<=N; i++) parent[i] = i;   
    memset(Rank, 1, sizeof(Rank)) ;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            Union(b, c);
        }
        else if(a == 1){
            if(Find(b,c)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}