#include<iostream>
#include<vector>

using namespace std;

vector<int> want;
vector<bool> visited;
vector<bool> done;
int result;

void DFS(int here){
    visited[here] = true;
    int there = want[here];
    if(!visited[there]) DFS(there);
    else if(!done[there]){
        for(int i = there; i != here; i = want[i]){
            result++;
        }
        result++;
    }
    done[here] = true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        result = 0;
        want.clear(); visited.clear(); done.clear();
        want = vector<int>(N+1); visited = vector<bool>(N+1, false); done = vector<bool>(N+1, false);
        for(int i=1; i<=N; i++) cin >> want[i];
        for(int i=1; i<=N; i++) DFS(i);
        cout << N-result << "\n";
    }
}