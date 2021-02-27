#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int main(){
    string s;
    stack<char> st;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if( (s[i] - 'A') >=0 && (s[i] -'A') < 26) cout << s[i];
        else if(s[i] == '*' || s[i] == '/'){
            while(!st.empty()){
                if(st.top() == '(') break;
                if(st.top() == '-' || st.top() == '+') break;
                if(st.top() == '/' || st.top() == '*'){
                    cout << st.top();
                    st.pop();
                }
            }            
            st.push(s[i]);
        }
        else if(s[i] == '+' || s[i] == '-'){
            while(!st.empty()){
                if(st.top() == '(') break;
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty()){
                if(st.top() == '('){
                    st.pop();
                    break;
                }
                cout << st.top();
                st.pop();
            }
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}