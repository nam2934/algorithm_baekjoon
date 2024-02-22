#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        num[i] = num[i-1]+n;
    }
    for(int i=0; i<M; i++){
        int left, right;
        cin >> left >> right;
        cout << num[right] - num[left-1] << "\n";
    }
}