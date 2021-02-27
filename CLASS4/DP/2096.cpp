#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int min_result[3];
int max_result[3];
vector<vector<int> > board;
int N;

int main(){    
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cin >> N;
    board = vector<vector<int> >(3, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> board[j][i];
        }
    }
    for(int i=0; i<3; i++){
        min_result[i] = board[i][0];
        max_result[i] = board[i][0];
    }

    for(int i=1; i<N; i++){
        int max_0, max_1, max_2, min_0, min_1, min_2;
        min_0 = min(min_result[0], min_result[1]) + board[0][i];
        min_1 = min(min(min_result[0], min_result[1]), min_result[2]) + board[1][i];
        min_2 = min(min_result[1], min_result[2]) + board[2][i];
        max_0 = max(max_result[0], max_result[1]) + board[0][i];
        max_1 = max(max(max_result[0], max_result[1]), max_result[2]) + board[1][i];
        max_2 = max(max_result[1], max_result[2]) + board[2][i];
        max_result[0] = max_0;
        max_result[1] = max_1;
        max_result[2] = max_2;
        min_result[0] = min_0;
        min_result[1] = min_1;
        min_result[2] = min_2;
    }
    cout << max(max(max_result[0], max_result[1]), max_result[2]) << " ";
    cout << min(min(min_result[0], min_result[1]), min_result[2]);
}
