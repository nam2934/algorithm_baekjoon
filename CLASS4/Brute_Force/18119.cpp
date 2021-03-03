#include<iostream>
#include<vector>
#include<string>

using namespace std;
int alpha = 0;
vector<int> word;
int main(){
    ios_base::sync_with_stdio();
    cin.tie();

    int N, M;
    cin >> N >> M; 
    for(int i=0; i<26; i++) alpha = alpha + (1 << i);
    word = vector<int>(N, 0);
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            int current_alpha = s[j] - 'a';
            word[i] = (word[i] | (1 << current_alpha));
        }
    }
    for(int i=0; i<M; i++){
        int o;
        char x;
        cin >> o >> x;

        alpha ^= (1 << (x - 'a'));
        int num = N;
        for(int j=0; j<N; j++){
            if((word[j] & alpha) != word[j]) num--;
        }
        cout << num << "\n";
    }

}