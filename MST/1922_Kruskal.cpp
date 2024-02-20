#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M;
int parent[1001];
vector<pair<int, pair<int ,int > > > cost;

int Find(int a){
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    if(a < b) swap(a,b);
    parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count = 0;
    int result = 0;
    cin >> N >> M;   
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(cost.begin(), cost.end());
    for(int i=0; i<cost.size(); i++){
        int a = cost[i].second.first;
        int b = cost[i].second.second;
        int c = cost[i].first;
        if(Find(a) == Find(b)) continue;
        Union(a, b);
        result += c;
        count++;
        if(count == N-1) break;
    }
    cout << result;
}