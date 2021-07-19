#include<iostream>
#include<vector>

using namespace std;

int pal[2001][2001];
vector<int> num;

bool is_pal(int S, int E){
    if(S >= E) return true;
    int& ret = pal[S][E];
    if(ret == -1){
        ret = (is_pal(S+1, E-1) && (num[S] == num[E]));
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0; i<2001; i++){
        for(int j=0; j<2001; j++){
            pal[i][j] = -1;
        }
    }
    int N,M;
    cin >> N;
    num = vector<int>(N);
    for(int i=0; i<N; i++) cin >> num[i];
    cin >> M;
    while(M--){
        int S,E;
        cin >> S >> E;
        cout << is_pal(S-1,E-1) << "\n";
    }
}