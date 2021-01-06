#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<bool> > visited;
pair<int, int> Start, End;

int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int main(){    
    int testcase, length;
    cin >> testcase;
    while (testcase--){
        cin >> length;
        visited = vector<vector<bool> >(length, vector<bool>(length, false));
        cin >> Start.first >> Start.second;
        cin >> End.first >> End.second;
        
        queue<pair<int, pair<int,int> > > q;
        q.push(make_pair(0,make_pair(Start.first, Start.second)));
        visited[Start.second][Start.first] = true;

        while(!q.empty()){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int cnt = q.front().first;
            q.pop();

            if(x == End.first && y == End.second){
                cout << cnt << endl;
                break;
            }

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < length && ny < length){
                    if(!visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push(make_pair(cnt+1,make_pair(nx, ny)));
                    }
                }
            }
        }

        visited.clear();
    }
}