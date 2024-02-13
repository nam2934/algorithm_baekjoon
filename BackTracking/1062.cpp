#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<string> alpha;
int bitmask[26];

int result = -1;
int N, K;

void combination(int index, int choice){
    if(choice == 0){
        int tempResult = 0;
        for(int i=0; i<N; i++){
            bool flag = true;
            for(int j=0; j<alpha[i].size(); j++){
                if(bitmask[alpha[i][j] - 'a'] == 0){
                    flag = false;
                }
            }
            if(flag) tempResult++;
        }
        result = max(result, tempResult);
        return;
    }
    for(int i=index; i<26; i++){
        if(bitmask[i] != 1){
            bitmask[i] = 1;
            combination(i, choice-1);
            bitmask[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> N >> K;

    bitmask['a'-'a'] = 1;
    bitmask['n'-'a'] = 1;
    bitmask['t'-'a'] = 1;
    bitmask['i'-'a'] = 1;
    bitmask['c'-'a'] = 1;

    for(int i=0; i<N; i++){
        cin >> s;
        alpha.push_back(s);
    }
    if(K < 5){
        cout << '0';
        return 0;
    }    
    combination(0, K-5);
    cout << result;
}