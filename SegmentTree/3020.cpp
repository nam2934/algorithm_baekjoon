#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;


int segTree[500001] = {0,};
int arr[500001] = {0,};
int N, H;
int minValue = INT_MAX;
int minCount = 1;

int query(int idx){
    int result = 0;
    while(idx > 0){
        result += segTree[idx];
        idx -= idx & -idx;
    }
    return result;
}

void update(int idx, int value){
    while(idx <= H){
        segTree[idx] += value;
        idx += idx & -idx;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        if(i%2 == 0){
            update(1, 1);
            update(n+1, -1);
        }else{
            update(H-n+1, 1);          
        }
    }
    
    for(int i=1; i<=H; i++){
        int result = query(i);
        if(minValue > result){
            minCount = 1;
            minValue = result;
        }
        else if(minValue == result){
            minCount++;
        }
    }
    cout << minValue << " " << minCount << "\n";
}