#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int R,C;
int dist = 0;
int result = -1;
vector<vector<char> > twMap;
vector<vector<char> > discovered;
queue<pair<int, pair<int, int> > > Q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void extendWater(){
    queue<pair<int, int> > waterQ;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(twMap[i][j] == '*'){
                waterQ.push(make_pair(i, j));
            }
        }
    }
    while(!waterQ.empty()){
        pair<int, int> waterQTop = waterQ.front();
        int y = waterQTop.first;
        int x = waterQTop.second;
        waterQ.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && ny < R && nx < C){
                if(twMap[ny][nx] == '.') twMap[ny][nx] = '*';
            }
        }
    }
}

int main(){
    cin >> R >> C;
    twMap.assign(R, vector<char>(C));
    discovered.assign(R, vector<char>(C));
    pair<int, int> startVertex;
    pair<int, int> endVertex;
    for(int i=0; i<R; i++){
        string s;
        cin >> s;
        for(int j=0; j<C; j++){
            twMap[i][j] = s[j];
            if(twMap[i][j] == 'S') startVertex = make_pair(i, j);
        }
    }
    Q.push(make_pair(0, startVertex));
    discovered[startVertex.first][startVertex.second] = true;

    while(!Q.empty()){
        pair<int, pair<int, int> > qTop = Q.front();
        int y = qTop.second.first;
        int x = qTop.second.second;        
        Q.pop();
        if(dist == qTop.first){
            dist++;
            extendWater();
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && ny < R && nx < C){            
                if(twMap[ny][nx] == 'D'){
                    cout << qTop.first+1 << "\n";
                    return 0;
                }
                if(twMap[ny][nx] == '.' && !discovered[ny][nx]){
                    discovered[ny][nx] = true;
                    Q.push(make_pair(qTop.first+1, make_pair(ny, nx)));
                }
            }
        }
    }
    cout << "KAKTUS" << "\n";
}