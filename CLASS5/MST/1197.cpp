#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[10001];

struct edge{
    int v1;
    int v2;
    int w;
    edge(int v1, int v2, int w) : v1(v1), v2(v2), w(w) {};
};

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    parent[u] = v;
}

bool comp(edge& e1, edge& e2){
    return e1.w < e2.w;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int V,E,result = 0;
    for(int i=0; i<10001; i++) parent[i] = i;
    vector<edge> eg;
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        eg.push_back(edge(v1, v2, w));
    }
    sort(eg.begin(), eg.end(), comp);
    for(int i=0; i<E; i++){
        if(find(eg[i].v1) != find(eg[i].v2)){
            merge(eg[i].v1, eg[i].v2);
            result += eg[i].w;
        }
    }
    cout << result;
}