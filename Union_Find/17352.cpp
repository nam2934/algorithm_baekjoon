#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> parents;
vector<int> Rank;

int Find(int a){
    if(a == parents[a]) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(Rank[u] > Rank[v]) swap(u,v);
    if(Rank[u] == Rank[v]) Rank[v]++; 
    parents[u] = v;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int N, first_island, second_island;
    cin >> N;
    parents = vector<int>(N+1);
    Rank = vector<int>(N, 1);

    for(int i=1; i<=N; i++){
        parents[i] = i;
    }
    for(int i=0; i<N-2; i++){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    first_island = Find(1);
    second_island = Find(1);
    for(int i=2; i<=N; i++){
        if(first_island != Find(i)){
            second_island = Find(i);
        }
    }
    cout << first_island << " " << second_island;
}