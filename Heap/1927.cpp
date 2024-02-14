#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
vector<int> minHeap;

void changeHeap(int node){
    int index = minHeap.size()- 1;
    while(index > 1){
        int parentIndex = index / 2;
        if(minHeap[index] < minHeap[parentIndex]){
            int temp = minHeap[index];
            minHeap[index] = minHeap[parentIndex];
            minHeap[parentIndex] = temp;
            index = parentIndex;
        }
        else break;
    }
}

void insertHeap(int node){
    minHeap.push_back(node);
    changeHeap(node);
}

void deleteHeap(){
    if(minHeap.size() == 1){
        cout << 0 << "\n";
        return;
    }
    int result = minHeap[1];
    int index = 1;
    cout << result << "\n";
    minHeap[1] = minHeap[minHeap.size()-1];
    minHeap.resize(minHeap.size()-1);
    while(index < minHeap.size()){
        int childIndex = index*2;
        if(childIndex+1 < minHeap.size() && minHeap[index] > minHeap[childIndex+1] && minHeap[childIndex] > minHeap[childIndex+1]){
            int temp = minHeap[index];
            minHeap[index] = minHeap[childIndex+1];
            minHeap[childIndex+1] = temp;             
            index = childIndex+1;
        }
        else if(childIndex < minHeap.size() && minHeap[index] > minHeap[childIndex]){
            int temp = minHeap[index];
            minHeap[index] = minHeap[childIndex];
            minHeap[childIndex] = temp;            
            index = childIndex;
        }
        else break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    minHeap.push_back(-1);
    while(N--){
        int n;
        cin >> n;
        if(n == 0){
            deleteHeap();
        }
        else{
            insertHeap(n);
        }
    }
}