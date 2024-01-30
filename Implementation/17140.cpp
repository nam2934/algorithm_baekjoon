#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<utility>

using namespace std;

vector<vector<int> > A(3, vector<int>(3));
int r,c,k;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

bool checkCondition(){
    if(r < A.size() && c < A[0].size() && A[r][c] == k) return true;
    return false;
}

void processing(){
    int max_size = 0;
    for(auto &i : A){
        map<int,int> m;
        vector<pair<int, int> > v;
        for(auto j : i){
            if(j == 0) continue;
            m[j]++;
        }
        v = vector<pair<int, int> >(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        if(v.size() >= 50){
            v.resize(50);
        }
        max_size = max(max_size, (int)v.size()*2);
        i.resize(v.size()*2);
        for(int j=0; j<v.size(); j++){
            i[j*2] = v[j].first;
            i[j*2+1] = v[j].second;
        }
    }
    for(auto &i : A){
        i.resize(max_size, 0);               
    }
}

void transposeVector(){
    vector<vector<int> > newV(A[0].size(), vector<int>(A.size()));
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            newV[j][i] = A[i][j];
        }
    }
    A.clear();
    A = newV;
}

int main(){
    int time = 0;
    int result = -1;
    cin >> r >> c >> k;
    r--;
    c--;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    while(1){
        if(time > 100){
            cout << -1;
            return 0;
        }
        if(checkCondition()) break;
        if(A.size() >= A[0].size()){
            processing();
        } else{
            transposeVector();
            processing();     
            transposeVector();
        }   
        time++;
    }
    cout << time;
}