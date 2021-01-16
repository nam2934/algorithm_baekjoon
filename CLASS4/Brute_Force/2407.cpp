#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<vector<string> > cache;

string big_sum(string a, string b){
    string result;
    int sum = 0;
    while(!a.empty() || !b.empty() || sum){
        if(!a.empty()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back(sum % 10 + '0');
        sum = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r){
    if(n == r || r == 0) return "1";
    string& ret = cache[n][r];
    if(ret == ""){
        return ret = big_sum(combination(n-1,r-1), combination(n-1,r));
    }
    return ret;
}

int main(){
    int N,M;
    long long result;
    cin >> N >> M;
    cache = vector<vector<string> >(N+1, vector<string>(M+1, ""));
    cout << combination(N,M);
}