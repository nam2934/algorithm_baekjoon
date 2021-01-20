#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > cache;
vector<int> red_costs;
vector<int> green_costs;
vector<int> blue_costs;

int solve(int index, int color){
    if(index == 0 && color == 0) return red_costs[0];
    if(index == 0 && color == 1) return green_costs[0];
    if(index == 0 && color == 2) return blue_costs[0];

    int& ret = cache[index][color];
    if(ret == -1){
        if(color == 0) return ret = min(solve(index-1, 1), solve(index-1,2)) + red_costs[index];
        if(color == 1) return ret = min(solve(index-1, 0), solve(index-1,2)) + green_costs[index];
        if(color == 2) return ret = min(solve(index-1, 0), solve(index-1,1)) + blue_costs[index];
    }
    return ret;   
}

int main(){
    int number_of_house;
    cin >> number_of_house;
    for(int i=0; i<number_of_house; i++){
        int red_cost, green_cost, blue_cost;
        cin >> red_cost >> green_cost >> blue_cost;
        red_costs.push_back(red_cost);
        green_costs.push_back(green_cost);
        blue_costs.push_back(blue_cost);
    }

    cache = vector<vector<int> >(number_of_house, vector<int>(3, -1));

     cout << min(solve(number_of_house-1, 0), min(solve(number_of_house-1,1), solve(number_of_house-1, 2)));    
}
