#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
vector<int> idx;

void ordered(int in_start, int in_end, int post_start, int post_end){
    int root, L, R;
    if(in_end < in_start || post_start > post_end){
        return;
    };
    root = postorder[post_end];
    L = idx[root];
    cout << root << " ";
    ordered(in_start,L-1,post_start,post_start+L-in_start-1);
    ordered(L+1,in_end,post_start+L-in_start,post_end-1);
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    cin >> n;
    idx = vector<int>(n+1);
    inorder = vector<int>(n);
    postorder = vector<int>(n);
    for(int i=0; i<n; i++) cin >> inorder[i];
    for(int i=0; i<n; i++) cin >> postorder[i];
    for(int i=0; i<n; i++) idx[inorder[i]] = i;
    ordered(0,n-1,0,n-1);
}
