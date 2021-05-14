#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int moving[101] = {0,};
int d[101];

int main(){
    memset(d, -1, sizeof(d));
    int ladder, snake;
    cin >> ladder >> snake;
    for(int i=0; i<ladder+snake; i++){
        int x,y;
        cin >> x >> y;
        moving[x] = y;
    }
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int there = here + i;
            if(there > 100) continue;
            if(moving[there] != 0) there = moving[there];
            if(d[there] == -1){
                d[there] = d[here] + 1;
                q.push(there);
            }
        }
    }
    cout << d[100];
}
