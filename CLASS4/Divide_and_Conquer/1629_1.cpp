#include<iostream>
#include<vector>
using namespace std;
int A,B,C;

long long divide(int B){
    if(B == 1) return A;
    if(B % 2 == 1) return divide(B/2)*(divide(B/2)*A%C)%C;
    else return divide(B/2)*divide(B/2)%C;
}

int main(){
    cin >> A >> B >> C;
    cout << divide(B)%C;
}