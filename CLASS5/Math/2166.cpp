#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int vertex;
    double area = 0.0;
    vector<double> x_arr, y_arr;
    cin >> vertex;
    for(int i=0; i<vertex; i++){
        double x,y;
        cin >> x >> y;
        x_arr.push_back(x);
        y_arr.push_back(y);
    }
    for(int i=0; i<vertex; i++){
        double sum_y;
        if(i == 0) sum_y = y_arr[i+1] - y_arr[vertex-1];
        if(i == vertex-1) sum_y = y_arr[0] - y_arr[i-1];
        if(i>=1 && i<vertex-1) sum_y = y_arr[i+1] - y_arr[i-1];
        area += x_arr[i]*sum_y;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(area)/2;
}