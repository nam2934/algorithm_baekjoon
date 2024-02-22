#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[1025][1025];
int arr[1025][1025];

int DP(int x, int y){
    if(x == 0 || y == 0) return 0;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = DP(x-1, y) + DP(x, y-1) - DP(x-1, y-1) + arr[y][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<M; i++){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << DP(x2, y2) - DP(x1-1, y2) - DP(x2, y1-1) + DP(x1-1, y1-1) << "\n";
    }
}