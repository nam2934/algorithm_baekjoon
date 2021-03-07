#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int N;

vector<vector<int> > board;

vector<vector<int> > Dijkstra(int y, int x){
    vector<vector<int> > dist;
    dist = vector<vector<int> >(N, vector<int>(N, INT_MAX));
    priority_queue<pair<int, pair<int,int> > > pq;
    dist[y][x] = board[y][x];
    pq.push(make_pair(-board[y][x], make_pair(y, x)));
    while(!pq.empty()){
        int cur_y = pq.top().second.first;
        int cur_x = pq.top().second.second;
        int cur_dist = -pq.top().first;
        pq.pop();
        if(cur_dist > dist[cur_y][cur_x]) continue;
        for(int i=0; i<4; i++){
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny >= 0 && nx >=0 && ny < N && nx < N){
                int next_dist = cur_dist + board[ny][nx];
                if(dist[ny][nx] > next_dist){
                    dist[ny][nx] = next_dist;
                    pq.push(make_pair(-next_dist, make_pair(ny, nx)));
                }
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    
    int count = 0;
    while(1){
        count++;
        cin >> N;
        if(N == 0) return 0;
        board.clear();
        board = vector<vector<int> >(N, vector<int>(N));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }
        vector<vector<int> > result = Dijkstra(0,0);
        cout << "Problem " << count << ": " << result[N-1][N-1] << "\n"; 
    }
    

}