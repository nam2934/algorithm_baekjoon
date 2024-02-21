#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int W, H, G, E;
vector<vector<int> > board;
vector<vector<int> > dist;
vector<vector<pair<int, pair<int, int > > > > hole;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
#define INF 987654321

bool Bellmanford(int y, int x){
    dist[y][x] = 0;
    for(int i=0; i<W*H; i++){
        for(int j=0; j<H; j++){
            for(int k=0; k<W; k++){
                int ny, nx, cost;
                if(k == W-1 && j == H-1) continue;
                if(hole[j][k].second.first != -1 && hole[j][k].second.second != -1){
                    ny = hole[j][k].second.first;
                    nx = hole[j][k].second.second;
                    cost = hole[j][k].first;
                    if(dist[j][k] == INF) continue;
                    if(dist[ny][nx] > dist[j][k] + cost) dist[ny][nx] = dist[j][k] + cost;
                }               
                else{
                    if(board[j][k] == 1) continue;
                    for(int h=0; h<4; h++){         
                        nx = dx[h] + k; 
                        ny = dy[h] + j;
                        if(nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == 0){
                            cost = 1;
                            if(dist[j][k] == INF) continue;
                            if(dist[ny][nx] > dist[j][k] + cost) dist[ny][nx] = dist[j][k] + cost;
                        }
                    }                    
                } 
            }
        }
    }
    for(int j=0; j<H; j++){
        for(int k=0; k<W; k++){
            int ny, nx, cost;
            if(k == W-1 && j == H-1) continue;
            if(hole[j][k].second.first != -1 && hole[j][k].second.second != -1){
                ny = hole[j][k].second.first;
                nx = hole[j][k].second.second;
                cost = hole[j][k].first;
                if(dist[j][k] == INF) continue;
                if(dist[ny][nx] > dist[j][k] + cost) return true;
            }               
            else{
                if(board[j][k] == 1) continue;
                for(int h=0; h<4; h++){         
                    nx = dx[h] + k; 
                    ny = dy[h] + j;
                    if(nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == 0){
                        cost = 1;
                        if(dist[j][k] == INF) continue;
                        if(dist[ny][nx] > dist[j][k] + cost) return true;
                    }
                }                    
            } 
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        cin >> W >> H;
        if(W == 0 && H == 0) return 0;
        board.assign(H, vector<int>(W, 0));
        hole.assign(H, vector<pair<int, pair<int, int> > >(W, make_pair(0, make_pair(-1, -1))));        
        dist.assign(H, vector<int>(W, INF));
        cin >> G;
        for(int i=0; i<G; i++){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        cin >> E;
        for(int i=0; i<E; i++){
            int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            hole[y1][x1] = make_pair(t, make_pair(y2, x2));
        }
        if(Bellmanford(0,0)){
            cout << "Never" << "\n";
        }
        else{
            if(dist[H-1][W-1] == INF) cout << "Impossible" << "\n";
            else cout << dist[H-1][W-1] << "\n";
        }
    }
}