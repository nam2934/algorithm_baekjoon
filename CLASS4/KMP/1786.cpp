#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> pi;

vector<int> getPartialMatch(const string& T){
    int m = T.size();
    vector<int> pi(m,0);
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(T[begin + matched] == T[matched]){
            matched++;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> KmpSearch(const string& T, const string& P){
    int t = T.size(), p = P.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(P);
    int begin = 0, matched = 0;
    while(begin <= t - p){
        if(matched < p && T[begin+matched] == P[matched]){
            matched++;
            if(matched == p) ret.push_back(begin);
        }
        else{
            if(matched == 0) begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main(){
    string T,P;
    getline(cin, T);
    getline(cin ,P);
    vector<int> result = KmpSearch(T,P);
    cout << result.size() << endl;
    for(auto i : result) cout << i+1 << " ";
}
