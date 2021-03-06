#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

vector<vector<int> > board;
vector<vector<bool> > visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int length, total_time=0, shark_size=2, min_cnt, fish_x, fish_y, eat_count=0;

void BFS(int x, int y){
    min_cnt = INT_MAX;
    fish_x=INT_MAX;
    fish_y=INT_MAX;
    //(x,y),count
    queue<pair<pair<int, int>,int> > Q;
    Q.push(make_pair(make_pair(x,y),0));
    visited[y][x] = true;
    while(!Q.empty()){
        int current_shark_x = Q.front().first.first;
        int current_shark_y = Q.front().first.second;
        int cnt = Q.front().second;
        
        if(cnt != 0 && board[current_shark_y][current_shark_x] < shark_size && board[current_shark_y][current_shark_x] != 0){
            if(min_cnt >= cnt){
                if(fish_y > current_shark_y){
                    min_cnt = cnt;
                    fish_y = current_shark_y;
                    fish_x = current_shark_x;
                }
                else if(fish_y == current_shark_y){
                    if(fish_x > current_shark_x){
                        min_cnt = cnt;
                        fish_y = current_shark_y;
                        fish_x = current_shark_x;
                    }
                }                
            }
        }

        Q.pop();

        for(int i=0; i<4; i++){
            int nx = current_shark_x + dx[i];
            int ny = current_shark_y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < length && ny < length){
                if(board[ny][nx] <= shark_size && !visited[ny][nx]){
                    Q.push(make_pair(make_pair(nx, ny),cnt+1));
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

void board_set(pair<int,int> start_shark){
    board[start_shark.second][start_shark.first] = 0;
    board[fish_y][fish_x] = 9;
}

bool exist_fish(){
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(board[i][j] < shark_size && board[i][j] != 0) return true;
        }
    }
    return false;
}

int main(){
    //(x,y)
    pair<int, int> start_shark;

    cin >> length;
    board = vector<vector<int> >(length, vector<int>(length));

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            int cell;
            cin >> cell;
            board[i][j] = cell;
            if(cell == 9){
                start_shark.first = j;
                start_shark.second = i;
            }
        }
    }
    min_cnt = 0;
    while(exist_fish()){
        visited = vector<vector<bool> >(length, vector<bool>(length, false));
        BFS(start_shark.first, start_shark.second);
        if(min_cnt == INT_MAX){
            break;
        }
        board_set(start_shark);
        start_shark.first = fish_x;
        start_shark.second = fish_y;
        eat_count++;
        if(eat_count == shark_size){
            shark_size++;;
            eat_count = 0;
        }
        total_time += min_cnt;
        visited.clear();
    }
    cout << total_time;
}