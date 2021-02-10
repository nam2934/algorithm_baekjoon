#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int LCS(string& s1, string& s2){
    int s1_size = s1.size();
    int s2_size = s2.size();
    int result[s1_size+1][s2_size+1];
    for(int i=0; i<=s1_size; i++){
        for(int j=0; j<=s2_size; j++){
            result[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=1; i<=s1_size; i++){
        for(int j=1; j<=s2_size; j++){
            if(s1[i-1] == s2[j-1]) result[i][j] = result[i-1][j-1] + 1;
            else if(s1[i-1] != s2[j-1]){
               result[i][j] = max(result[i-1][j], result[i][j-1]);
            }
            if(ans < result[i][j]){
                ans = result[i][j];
            }
        }
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
}