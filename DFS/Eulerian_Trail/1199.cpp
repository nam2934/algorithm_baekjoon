#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > adjArr;
vector<int> degree;

void getEulerCircuit(int here, vector<int>& circuit){
    for(int there=0; there < adjArr[here].size(); there++){
        while(adjArr[here][there] > 0){
            adjArr[here][there]--;
            adjArr[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

int main(){
    int N;
    cin >> N;
    adjArr = vector<vector<int> >(N, vector<int>(N));
    degree = vector<int>(N, 0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> adjArr[i][j];
            degree[i] += adjArr[i][j];
            degree[j] += adjArr[i][j];
        }
    }
    vector<int> circuit;
    getEulerCircuit(0, circuit);
    for(int i=0; i<N; i++){
        if((degree[i]/2) % 2 == 1){
            cout << -1;
            return 0;
        }
    }
    for(int i=0; i<circuit.size(); i++){
        cout << circuit[circuit.size()-i-1]+1 << " ";
    }
}