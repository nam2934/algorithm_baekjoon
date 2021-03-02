#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > origin_matrix;

vector<vector<int> > mul(int n, vector<vector<int> > a, vector<vector<int> > b){
    vector<vector<int> > result_matrix(n, vector<int>(n));
    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            int each_value = 0;
            for(int k=0; k<n; k++) each_value += a[i][k]*b[k][j];
            result_matrix[i][j] = each_value%1000;
        }
    }
    return result_matrix;
}

vector<vector<int> > pow_matrix(int n, long long b){
    if(b == 1) return origin_matrix;
    if(b % 2 != 0) return mul(n, pow_matrix(n, b-1), pow_matrix(n, 1));
    vector<vector<int> > devide_matrix = pow_matrix(n, b/2);
    return mul(n, devide_matrix, devide_matrix);
}

int main(){
    int N;
    long long B;
    cin >> N >> B;
    origin_matrix = vector<vector<int> >(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int each_value;
            cin >> each_value;
            origin_matrix[i][j] = each_value%1000;
        }
    }
    vector<vector<int> > result = pow_matrix(N, B);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}