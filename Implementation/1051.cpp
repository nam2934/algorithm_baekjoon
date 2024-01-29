#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void fillVector(vector<vector<int> >& square, const int h, const int w){
    for(int i=0; i<h; i++){
        string s;
        cin >> s;
        for(int j=0; j<w; j++){
            square[i][j] = s[j] - '0';
        }
    }
}

int computeSquare(const vector<vector<int> >& square, const int h, const int w){
    int result = 0;
    int shorter = h <= w ? h : w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            for(int k = 0; (k+i < h) && (k+j < w); k++){
                if(square[i][j] == square[i+k][j] && square[i][j] == square[i][j+k] && square[i][j] == square[i+k][j+k]) result = max(result, k);
            }
        }
    }
    return (result+1)*(result+1);
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int> > square(h,vector<int>(w));
    fillVector(square,h,w);
    cout << computeSquare(square,h,w);
}