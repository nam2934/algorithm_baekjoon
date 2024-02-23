#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

int maxVal[1001][1001];

int main(){
    string s1, s2;
    int result = 0;
    cin >> s1 >> s2;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            maxVal[i][j] = 0;
        }
    }
    for(int i=1; i<=s2.length(); i++){
        for(int j=1; j<=s1.length(); j++){
            if(s2[i-1] == s1[j-1]){
                maxVal[i][j] = maxVal[i-1][j-1] + 1;
            }
            else{
                maxVal[i][j] = max(maxVal[i-1][j], maxVal[i][j-1]);
            }
            result = max(result, maxVal[i][j]);
        }
    }
    cout << result  << "\n";

    stack<char> st;
    int y = s2.size();
    int x = s1.size();
    while(maxVal[y][x] != 0){
        if(maxVal[y][x] == maxVal[y][x-1]) x--;
        else if(maxVal[y][x] == maxVal[y-1][x]) y--;
        else{
            st.push(s1[x-1]);
            x--;
            y--;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}