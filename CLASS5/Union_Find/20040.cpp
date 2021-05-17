#include<iostream>
#include<vector>

using namespace std;

int parent[500000];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,M,result = 0;
    cin >> N >> M;
    for(int i=0; i<500000; i++) parent[i] = i;
    for(int i=1; i<=M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        if(find(v1) != find(v2)){
            merge(v1, v2);
        }
        else{
            cout << i;
            return 0;
        }
    }
    cout << 0;
}