#include<iostream>
#include<vector>

using namespace std;

int N, K;

int visited[1001] = {0, };

int main(){
    cin >> N >> K;
    int count =  0;
    for(int i=2; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            if(!visited[j]){
                visited[j] = 1;
                count++;
                if(count == K){
                    cout << j;
                    return 0;
                }
            }
        }
    }
}