#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int cache[4001][4001];

int main(){
    string s1, s2;
    int result = 0;
    cin >> s1 >> s2;
    for(int i=0; i<s1.length(); i++){
        for(int j=0; j<s2.length(); j++){
            if(s1[i] == s2[j]){
                cache[i][j] = 1;
                if(i == 0 || j == 0) continue;
                cache[i][j] = cache[i-1][j-1] + 1;
                result = max(result, cache[i][j]);
            }
        }
    }
    cout << result;
}