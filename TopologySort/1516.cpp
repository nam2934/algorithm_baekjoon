#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int N;
int arr[501];
int indegree[501];
int result[501];
vector<int> adjList[501];


void TopologySortBFS(){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0){
            q.push(i);
            result[i] = arr[i];
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<adjList[v].size(); i++){
            indegree[adjList[v][i]]--;
            result[adjList[v][i]] = max(result[adjList[v][i]], result[v] + arr[adjList[v][i]]);
            if(indegree[adjList[v][i]] == 0){
                q.push(adjList[v][i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    memset(indegree, 0, sizeof(indegree));
    for(int i=1; i<=N; i++){
        int n;
        cin >> arr[i];
        while(cin >> n){
            if(n == -1) break;
            adjList[n].push_back(i);
            indegree[i]++;
        }
    }
    TopologySortBFS();
    for(int i=1; i<=N; i++){
        cout << result[i] << "\n";
    }
}