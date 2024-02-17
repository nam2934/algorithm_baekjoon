#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> box;
vector<int> segTree;
int N;
int leafN = 1;

int query(int now, int value){
    if(now >= leafN) return now-leafN+1;
    int next = 2*now;
    if(segTree[next] >= value) return query(next, value);
    else return query(next+1, value - segTree[next]);
}

void update(int idx, int value){
    int now = idx+leafN-1;
    segTree[now] += value;
    now /= 2;
    while(now > 0){
        segTree[now] = segTree[now*2] + segTree[now*2+1];
        now /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(leafN < 1000000) leafN*=2;
    segTree = vector<int>(leafN*2+2, 0);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(a == 1){
            int b;
            cin >> b;
            int result = query(1, b);
            cout << result << "\n";
            update(result, -1);
        }
        else {
            int b, c;
            cin >> b >> c;
            update(b, c);
        }
    }
}