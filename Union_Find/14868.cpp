#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
pair<int,int> parents[2001][2001];
pair<int,int> visited[2001][2001];
int Rank[2001][2001];
int N,K;

pair<int,int> Find(pair<int,int> a){
    if(parents[a.first][a.second] == a) return a;
    return parents[a.first][a.second] = Find(parents[a.first][a.second]);
}

void Union(pair<int,int> u, pair<int,int> v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(Rank[u.first][u.second] < Rank[v.first][v.second]){
        swap(u, v);
    }
    if(Rank[u.first][u.second] == Rank[v.first][v.second]) Rank[u.first][u.second]++;
    parents[v.first][v.second] = u;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            parents[i][j] = make_pair(i,j);
            visited[i][j] = make_pair(0,0);
            Rank[i][j] = 1;
        }
    }
    queue<pair<pair<int,int>, int> > q;
    vector<pair<int,int> > input_civil;
    for(int i=0; i<K; i++){
        int x,y;
        cin >> x >> y; 
        q.push(make_pair(make_pair(x,y), 0));
        input_civil.push_back(make_pair(x,y));
        visited[x][y] = make_pair(x,y);
    }
    int prev_level = 0;
    bool if_first_attempt = true;
    vector<pair<int, int> > check_adj = input_civil;
    while(!q.empty()){
        int top_x = q.front().first.first;
        int top_y = q.front().first.second;
        int level = q.front().second;
        q.pop();

        if(prev_level != level || if_first_attempt){
            if_first_attempt = false;
            for(int i=0; i<check_adj.size(); i++){
                for(int j=0; j<4; j++){
                    int nx = check_adj[i].first + dx[j];
                    int ny = check_adj[i].second + dy[j];
                    if(nx >= 1 && ny >= 1 && nx <= N && ny <= N){
                        if(Find(check_adj[i]) != Find(make_pair(nx,ny)) && visited[nx][ny] != make_pair(0,0)){
                            Union(check_adj[i], make_pair(nx,ny));
                            K--;
                        }
                    }
                }
            }
            check_adj.clear();
            if(K == 1){
                cout << level << "\n";
                return 0;
            }
            else prev_level = level;
        }
        
        for(int i=0; i<4; i++){
            int nx = top_x + dx[i];
            int ny = top_y + dy[i];
            int next_level = level+1;
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N){
                if(visited[nx][ny] != make_pair(0,0)){
                    continue;
                }
                else{
                    visited[nx][ny] = make_pair(nx, ny);
                    Union(make_pair(top_x, top_y), make_pair(nx, ny));
                    q.push(make_pair(make_pair(nx,ny), next_level));
                    check_adj.push_back(make_pair(nx, ny));
                }
            }
        }
    }
}