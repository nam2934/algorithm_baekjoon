#include<iostream>
#include<string>
using namespace std;

int longest_substring(string& s1, string& s2){
    int s1_size = s1.size();
    int s2_size = s2.size();
    int result[s1_size+1][s2_size+1] = {0, };
    int ans = 0;
    for(int i=1; i<=s1_size; i++){
        for(int j=1; j<=s2_size; j++){
            if(s1[i-1] == s2[j-1]) result[i][j] = result[i-1][j-1]+1;
            if(ans < result[i][j]) ans = result[i][j];
        }
    }
    return ans;
}

int main(){
    string string1, string2;
    cin >> string1 >> string2;
    cout << longest_substring(string1, string2);
}