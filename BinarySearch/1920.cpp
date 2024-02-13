#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<long long> arr;
long long findArr[100001];

long long N,M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr = vector<long long>(N);
    for(long long i=0; i<N; i++) cin >> arr[i];
    cin >> M;
    sort(arr.begin(), arr.end());
    for(long long i=0; i<M; i++) cin >> findArr[i];
    for(long long i=0; i<M; i++){
        long long num = findArr[i];
        long long start = 0;
        long long end = N;
        bool isFind = false;
        while(end >= start){
            long long pivot = start + (end - start) / 2;
            if(arr[pivot] == num){
                isFind = true;
                break;
            }
            if(arr[pivot] < num){
                start = pivot+1;
            }
            if(arr[pivot] > num){
                end = pivot-1;
            }
        }
        if(isFind) cout << "1" << "\n";
        else cout << "0" << "\n";
    }
}