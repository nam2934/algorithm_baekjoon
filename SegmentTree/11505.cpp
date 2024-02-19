#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N,M,K;
int leafN = 1;
vector<int> arr;
vector<long long> segTree;

int query(int left, int right){
    long long result = 1;
    while(left <= right){
        if(left % 2 == 1){
            result *= segTree[left];
            result %= 1000000007;
            left += 1;
            
        }
        if(right % 2 == 0){
            result *= segTree[right];
            result %= 1000000007;
            right -= 1;
        }
        left /= 2;
        right /= 2;
    }
    return result % 1000000007;
}

void update(int idx, int value){
    int newIndex = leafN+idx-1;
    segTree[newIndex] = value;
    newIndex /= 2;
    while(newIndex > 0){
        segTree[newIndex] = ((segTree[newIndex*2] % 1000000007) * (segTree[newIndex*2+1] % 1000000007))% 1000000007;
        newIndex /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    while(leafN < N) leafN*=2;
    segTree = vector<long long>(leafN*2, 1);
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        update(i , n);
    }
    for(int i=0; i<M+K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else if(a == 2){
            cout << query(b + leafN - 1, c + leafN - 1) << "\n";
        }
    }
}