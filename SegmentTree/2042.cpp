#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M, K;
int leafN = 1;
vector<long long> segTree;

void initTree(){
    for(int i=leafN-1; i>=1; i--){
        segTree[i] = segTree[2*i]+segTree[2*i+1];
    }
}

// int findSum(int start, int end, int nodeStart, int nodeEnd, int index){
//     int result = 0;
//     int leftStart = start;
//     int leftEnd = (end-start+1)/2 - 1;
//     int rightStart = leftEnd+1;
//     int rightEnd = end;

//     if(start == nodeStart && end == nodeEnd){
//         return segTree[index];
//     }
//     if(start <= leftEnd){
//         result += findSum(start, leftEnd, nodeStart, leftEnd, index*2);
//     }
//     if(end >= rightStart){
//         result += findSum(rightStart, end, rightStart, end, index*2+1);
//     }
//     return result;
// }

long long get(int left, int right){
    long long sum = 0;
    left = left + leafN-1;
    right = right + leafN-1;
    
    while(left<=right){
        if(left % 2 == 1){
            sum = sum + segTree[left];
            left = left + 1;
        }
        if(right % 2 == 0){
            sum = sum + segTree[right];
            right = right -1;
        }
        left = left /2;
        right = right /2;
    }
    return sum;
}

void updateNode(int index, long long value){
    segTree[index] = value;
    for(int i=index/2; i>=1; i/=2){
        segTree[i] = segTree[i*2] + segTree[i*2+1];
    }
}

int main(){
    cin >> N >> M >> K;
    while(N > leafN) leafN*=2;
    segTree = vector<long long>(leafN*2, 0);
    for(int i=leafN; i<leafN+N; i++) cin >> segTree[i];
    initTree();
    for(int i=0; i<M+K; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            updateNode(b+leafN-1, c);
        }
        else if(a == 2){
            cout << get(b, c) << "\n";
        }
    }
}