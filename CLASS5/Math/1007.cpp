#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;

vector<pair<int, int> > coor;
vector<int> empty_vec;
vector<vector<int> > com_result;

void com(int n, vector<int>& picked, int to_pick){
    if(to_pick == 0){
        com_result.push_back(picked);
    }
    int smallest = picked.empty() ? 0 : picked.back()+1;
    for(int i=smallest; i<n; i++){
        picked.push_back(i);
        com(n, picked, to_pick-1);
        picked.pop_back();
    }
}

int main(){
    cout<<fixed;
    cout.precision(12);
    int T;
    cin >> T;
    while(T--){
        long long tot_x = 0, tot_y = 0;
        long long result = 9223372036854775807;
        cin >> N;
        coor = vector<pair<int, int> >(N);
        com_result.clear();
        empty_vec.clear();
        for(int i=0; i<N; i++){
            cin >> coor[i].first >> coor[i].second;
            tot_x += coor[i].first;
            tot_y += coor[i].second;
        }
        com(N, empty_vec, N/2);
        for(int i=0; i<com_result.size(); i++){
            long long sum_x = 0;
            long long sum_y = 0;
            for(int j=0; j<com_result[i].size(); j++){
                sum_x += coor[com_result[i][j]].first;
                sum_y += coor[com_result[i][j]].second;
            }
            long long result_x = sum_x - (tot_x - sum_x);
            long long result_y = sum_y - (tot_y - sum_y);
            result = min(result, result_x*result_x + result_y*result_y);
        }
        cout << (double)sqrt(result) << "\n";
    }
}