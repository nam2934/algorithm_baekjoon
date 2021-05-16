#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100001];

struct edge{
    int v1,v2,w;
    edge(int v1, int v2, int w) : v1(v1), v2(v2), w(w) {}
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

bool comp(const edge& e1, const edge& e2){
    return e1.w < e2.w;    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<edge> eg;
    vector<int> weight;
    int N,M,result = 0;
    cin >> N >> M;
    for(int i=0; i<100001 ; i++) parent[i] = i;
    for(int i=0; i<M; i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        eg.push_back(edge(v1,v2,w));
    }
    sort(eg.begin(), eg.end(), comp);
    for(auto i : eg){
        if(find(i.v1) != find(i.v2)){
            merge(i.v1, i.v2);
            weight.push_back(i.w);
        }
    }
    for(int i=0; i<weight.size()-1; i++){
        result += weight[i];
    }
    cout << result;
}