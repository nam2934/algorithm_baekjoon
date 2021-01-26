#include<iostream>
using namespace std;

int main(){
    int start, end, cnt = 0;
    cin >> start >> end;
    while(1){
        if(end == start){
            cout << cnt+1 << "\n";
            break;
        }
        else if(end < start){
            cout << -1 << "\n";
            break;
        }
        else if(end % 10 == 1){
            end /= 10;
        }
        else if(end % 2 == 0){
            end /= 2;
        }
        else{
            cout << -1 << "\n";
            break;
        }
        cnt++;
    }
}