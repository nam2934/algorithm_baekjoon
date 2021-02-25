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
    parents[u] = v;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    parents = vector<int>(n+1);
    Rank = vector<int>(n+1, 1);
    for(int i=0; i<=n; i++) parents[i] = i;
    for(int i=0; i<m; i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 0) Union(a,b);
        else if(Find(a) == Find(b)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}  