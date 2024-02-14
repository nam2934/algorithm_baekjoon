#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

int main(){
    string s;
    stack<int> st;
    int value = 0;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(') st.push(-1);
        else if(s[i] == '[') st.push(-2);
        else{
            if(s[i] == ')'){
                if(!st.empty() && st.top() == -1){
                    st.pop();
                    st.push(2);
                }
                else if(!st.empty() && st.top() >= 0){
                    int temp = 0;
                    while(!st.empty() && st.top() >= 0){
                        temp += st.top();
                        st.pop();
                    }
                    if(!st.empty() &&st.top() == -1){
                        st.pop();
                        st.push(temp*2);
                    }
                    else if(st.empty() || st.top() == -2){
                        cout << 0;
                        return 0;
                    }
                }
                else{
                    cout << 0;
                    return 0;
                }
            }
            if(s[i] == ']'){
                if(!st.empty() && st.top() == -2){
                    st.pop();
                    st.push(3);
                }
                else if(!st.empty() && st.top() >= 0){
                    int temp = 0;
                    while(!st.empty() && st.top() >= 0){
                        temp += st.top();
                        st.pop();
                    }
                    if(!st.empty() && st.top() == -2){
                        st.pop();
                        st.push(temp*3);
                    }
                    else if(st.empty() ||st.top() == -1){
                        cout << 0;
                        return 0;
                    }
                }
                else{
                    cout << 0;
                    return 0;
                }                
            }          
        }
    }
    while(!st.empty()){
        if(st.top() == -1 || st.top() == -2){
            cout << 0;
            return 0;
        }
        value += st.top();
        st.pop();
    }
    cout << value;
}