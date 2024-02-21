#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<long long> segTree;
vector<long long> arr;
vector<pair<int, int> > land;

int T, N;

bool comp1(pair<int, int>& a, pair<int, int>& b){
    if(a.second < b.second) return true;
    else return false;
}

bool comp2(pair<int, int>& a, pair<int, int>& b){
    if(a.first > b.first) return true;
    // 이부분 빼먹으면 안된다.. 조심..
    else if(a.first == b.first){
        return a.second < b.second;
    }
    return false;
}

void update(int now, int start, int end, int idx, long long value){
    if(idx < start || idx > end) return;
    segTree[now] += value;
    if(start == end) return;
    int next = now*2;
    int mid = (start + end) / 2;
    update(next, start, mid, idx, value);
    update(next+1, mid+1, end, idx, value);
}

long long query(int now, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return (long long)segTree[now];
    int next = now*2;
    int mid = (start + end) / 2;
    return query(next, start, mid, left, right) + query(next+1, mid+1, end, left, right);
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        int index = 1;
        long long result = 0;
        cin >> N;
        land.clear();
        for(int i=0; i<N; i++){
            int x, y;
            cin >> x >> y;
            land.push_back(make_pair(x, y));
        }
        sort(land.begin(), land.end(), comp1);
        segTree.assign(N*4, 0);
        arr.assign(N+1, 0);

        int oldY = land[0].second;
        land[0].second = index;
        for(int i=1; i<N; i++){
            if(oldY == land[i].second){
                land[i].second = land[i-1].second;
            }
            else{
                oldY = land[i].second;
                index++;
                land[i].second = index;
            }
        }
        sort(land.begin(), land.end(), comp2);
        for(int i=0; i<land.size(); i++){
            long long temp = query(1, 1, N, 1, land[i].second);
            result += temp;
            if(i == land.size()-1){
                break;
            }
            update(1, 1, N, land[i].second, 1);
        }
        cout << result << "\n";
    }
}