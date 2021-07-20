#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int pal[2001][2001];
int cache[2001];
string s;
int e;

bool is_pal(int st, int e){
    if(st >= e) return true;
    int& ret = pal[st][e];
    if(ret == -1){
        ret = ((s[st] == s[e]) && is_pal(st+1, e-1));
    }
    return ret;
}

int count_pal(int start){
    if(start > e) return 0;
    int& ret = cache[start];
    if(ret == 987654321){
        for(int i=0; i<e-start+1; i++){
            if(is_pal(start, start+i)){
                ret = min(ret, count_pal(start+i+1)+1);
            }
        }
    }
    return ret;
}

int main(){
    int result = 987654321;
    for(int i=0; i<2001; i++){
        for(int j=0; j<2001; j++){
            pal[i][j] = -1;
            cache[i] = 987654321;
        }
    }
    cin >> s;
    e = s.size()-1;
    cout << count_pal(0);
}