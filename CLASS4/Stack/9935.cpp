#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s;
    string bomb;
    vector<char> st;
    cin >> s >> bomb;
    for(int i=0; i<s.size(); i++){
        st.push_back(s[i]);
        if(s[i] == bomb.back()){
            bool check = true;
            int index = 0;
            for(int j=bomb.size()-1; j>=0; j--){
                if(st.size()-1-index >= 0 && bomb[j] == st[st.size()-1-index]){
                    index++;
                }
                else{
                    check = false;
                    break;
                }
            }
            if(check){
                for(int j=0; j<index; j++){
                    st.pop_back();
                }
            }
        }
    }
    if(st.empty()){
        cout << "FRULA";
        return 0;
    }
    for(auto i : st) cout << i;
}