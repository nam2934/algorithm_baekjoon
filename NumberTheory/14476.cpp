#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int numbers[1000001];
vector<int> GCDs[2];

int GCD(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    int result = -1;
    bool flag = false;
    cin >> N;
    memset(numbers, 0, sizeof(numbers));
    for(int i=0; i<N; i++){
        cin >> numbers[i];
    }
    K = numbers[0];
    GCDs[0].push_back(0);
    GCDs[1].push_back(0);
    for(int i=0; i<N; i++){
        if(i == 0) GCDs[0].push_back(numbers[i]);
        else GCDs[0].push_back(GCD(GCDs[0][i], numbers[i]));
    }
    for(int i=N-1; i>=0; i--){
        if(i == N-1) GCDs[1].push_back(numbers[i]);
        else GCDs[1].push_back(GCD(GCDs[1][N-1-i], numbers[i]));
    }    

    for(int i=1; i<=N; i++){
        int newResult = GCD(GCDs[0][i-1], GCDs[1][N-i]);
        if(result < newResult){
            result = newResult;
            K = numbers[i-1];
        }
        if(numbers[i-1] < result || numbers[i-1] % result != 0) flag = true;
    }
    if(flag) cout << result << " " << K;
    else cout << -1;
}