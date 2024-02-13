#include<iostream>

using namespace std;

int A[10001];

int main(){
    int N, M;
    int point1 = 0, point2 = 0, result = 0;
    int sum_ = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> A[i];
    while(point2 <= N){
        if(sum_ < M){
            sum_ += A[point2];
            point2++;
        }
        else if(sum_ >= M){
            if(sum_ == M) result++;
            sum_ -= A[point1];
            point1++;
        }
    }
    cout << result;
}