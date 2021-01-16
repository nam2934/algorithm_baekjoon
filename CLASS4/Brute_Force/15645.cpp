#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> numArr;
vector<bool> visit;

void pick(int N, vector<int>& picked, int toPick){
    if(toPick == 0){
        for(int i : picked){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(visit[i]){
            continue;
        }
        else{
            picked.push_back(numArr[i]);
            visit[i] = true;
            pick(N, picked, toPick-1);
            picked.pop_back();
            visit[i] = false;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    vector<int> picked;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        numArr.push_back(num);
    }
    visit = vector<bool>(N, false);
    sort(numArr.begin(), numArr.end());
    pick(N,picked,M);
}