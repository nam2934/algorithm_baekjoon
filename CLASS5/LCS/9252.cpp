#include<iostream>
#include<string>
#include<cmath>
#include<stack>
using namespace std;

string LCS(string& s1, string& s2){
    string s="";
    int result[s2.size()+1][s1.size()+1];
    for(int i=0; i<=s2.size(); i++){
        for(int j=0; j<=s1.size(); j++){
            result[i][j] = 0;
        }
    }
    for(int i=1; i<=s2.size(); i++){
        for(int j=1; j<=s1.size(); j++){
            if(s2[i-1] == s1[j-1]) result[i][j] = result[i-1][j-1] + 1;
            else{
                result[i][j] = max(result[i-1][j], result[i][j-1]);
            }
        }
    }
    stack<char> st;
    int y = s2.size();
    int x = s1.size();
    while(result[y][x] != 0){
        if(result[y][x] == result[y][x-1]) x--;
        else if(result[y][x] == result[y-1][x]) y--;
        else{
            st.push(s1[x-1]);
            x--;
            y--;
        }
    }
    while(!st.empty()){
        s += st.top();
        st.pop();
    }
    return s;
}

int main(){
    string s1, s2, result;
    cin >> s1 >> s2;
    result = LCS(s1,s2);
    cout << result.size() << endl << result << endl;
}