#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct edge{
    int v1, v2;
    double w;
    edge(int v1, int v2, double w) : v1(v1), v2(v2), w(w) {};
};

struct pos{
    double x,y;
    pos(double x, double y) : x(x), y(y) {};
};

vector<pos> board;
vector<edge> eg;
int parent[100];

double dist(pos p1, pos p2){
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    parent[u] = v;
}

bool comp(edge e1, edge e2){
    return e1.w < e2.w;
}

int main(){
    int N;
    double result = 0.0;
    cin >> N;
    for(int i=0; i<100; i++) parent[i] = i;
    for(int i=0; i<N; i++){
        double x,y;
        cin >> x >> y;
        board.push_back(pos(x,y));
    }
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            eg.push_back(edge(i,j,dist(board[i], board[j])));
        }
    }
    sort(eg.begin(), eg.end(), comp);
    //for(auto i : eg) cout << i.v1 << " " <<  i.v2 << " " << i.w << endl;
    for(int i=0; i<eg.size(); i++){
        if(find(eg[i].v1) != find(eg[i].v2)){
            merge(eg[i].v1, eg[i].v2);
            result += eg[i].w;
        }
    }
    cout << (double)((int)(result*100))/100;
}