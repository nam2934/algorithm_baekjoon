#include<iostream>
#include<vector>

using namespace std;

int N,M,K;
vector<vector<int> > mat;
vector<vector<bool> > visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void getMat(){
    int x, y;
    cin >> M >> N >> K;
    mat.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    for(int i=0; i<K; i++){
        cin >> x >> y;
        mat[y][x] = 1;
    }
}

void DFS(int y, int x){
    visited[y][x] = true;
    for(int i=0; i<4; i++){
        int newX = x+dx[i];
        int newY = y+dy[i];
        if(newY < N && newX < M && newX >= 0 && newY >= 0){
            if(mat[newY][newX] == 1 && !visited[newY][newX]) DFS(newY, newX);
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int result = 0;
        getMat();
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(mat[i][j] != 1) continue;
                if(!visited[i][j]){
                    result++;
                    DFS(i, j);
                }
            }
        }
        cout << result << "\n";
    }
}