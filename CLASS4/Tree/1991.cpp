#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int label;
    TreeNode* left;
    TreeNode* right;
};

vector<TreeNode*> tree;

int main(){    
    int N;
    cin >> N;
    tree = vector<TreeNode*>(N);
    for(int i=0; i<N; i++){
        tree[i] = new TreeNode;
    }
    for(int i=0; i<N; i++){
        char current_value, left_value, right_value;
        cin >> current_value >> left_value >> right_value;
        tree[i]->label = current_value-'A';
        if(left_value == '.' || right_value == '.'){
            if(left_value == '.') tree[i]->left = NULL;
            if(right_value == '.') tree[i]->right = NULL;
            continue;
        }
        tree[i]->left = tree[left_value-'A'];
        tree[i]->right = tree[right_value-'A'];
    }
    cout << tree[0]->label << " " << tree[0]->left->label << " " << tree[0]->right->label;
}