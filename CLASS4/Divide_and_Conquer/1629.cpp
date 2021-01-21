#include<iostream>
using namespace std;
long long A,B,C;

long long divide(long long B){
    if(B == 0){
        return 1;
    }
    long long next = divide(B/2);
    if(B % 2){
        return ((next*next)%C*A)%C;
    }
    else{
        return (next*next)%C;
    }
}

int main(){
    cin >> A >> B >> C;
    cout << divide(B)%C;
}