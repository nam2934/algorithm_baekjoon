#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> A,B,C,D;
vector<int> CD;
vector<int> AB;
long long result = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N);
    B = vector<int>(N);
    C = vector<int>(N);
    D = vector<int>(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int sum_ = C[i] + D[j];
            CD.push_back(sum_);
        }
    }
    sort(CD.begin(), CD.end());
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int sum_ = A[i] + B[j];
            AB.push_back(sum_);
        }
    }
    sort(AB.begin(), AB.end(), greater<int>());    
    int point1 = 0, point2 = 0;
    while(point2 < N*N && point1 < N*N){
        if(AB[point1] + CD[point2] < 0) point2++;
        else if(AB[point1] + CD[point2] >= 0){
            if(AB[point1] + CD[point2] == 0){
                long long countAB = 1;
                long long countCD = 1;
                while(point2+1 < N*N && CD[point2] == CD[point2+1]){
                    point2++;
                    countCD++;
                }
                while(point1+1 < N*N && AB[point1] == AB[point1+1]){
                    point1++;
                    countAB++;
                }
                result += countAB*countCD;
            }
            point1++;
        }
    }
    cout << result;
}