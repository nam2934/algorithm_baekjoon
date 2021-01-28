#include<iostream>
#include<cmath>
using namespace std;

int N;
int result = 0;
int col[15];

void go(int i){
    if(i == N) result++;
    else{
        for(int j=0; j<N; j++){
            bool flag = true;
            col[i] = j;
            for(int k=0; k<i; k++){
                if(col[k] == col[i] || abs(col[i]-col[k]) == i-k){
                    flag = false;
                }                    
            }
            if(flag){
                go(i+1);
            }            
        }
    }
}

int main(){
    cin >> N;
    go(0);
    cout << result;
}