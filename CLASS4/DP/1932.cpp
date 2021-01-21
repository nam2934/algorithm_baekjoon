#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int height;
vector<vector<int> > triangle;
vector<vector<int> > cache;

int DP(int current_height, int index){
    if(current_height == height-1) return triangle[height-1][index];
    int& ret = cache[current_height][index];

    if(ret == -1){
        return ret = max(DP(current_height+1, index), DP(current_height+1, index+1)) + triangle[current_height][index];
    }
    return ret;
}
int main(){
    cin >> height;
    triangle = vector<vector<int> >(height);
    cache = vector<vector<int> >(height, vector<int>(height, -1));
    for(int i=0; i<height; i++){
        for(int j=0; j<=i; j++){
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }
    cout << DP(0, 0);
}
