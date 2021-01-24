#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int label;
    TreeNode* left;
    TreeNode* right;
};

vector<TreeNode*> tree;

void preorder(int i){
    char result = (tree[i]->label +'A');
    cout << result;
    if(tree[i]->left != NULL) preorder(tree[i]->left->label);
    if(tree[i]->right != NULL) preorder(tree[i]->right->label);
}

void inorder(int i){
    char result = (tree[i]->label +'A');
    if(tree[i]->left != NULL) inorder(tree[i]->left->label);
    cout << result;
    if(tree[i]->right != NULL) inorder(tree[i]->right->label);
}

void postorder(int i){
    char result = (tree[i]->label +'A');
    if(tree[i]->left != NULL) postorder(tree[i]->left->label);
    if(tree[i]->right != NULL) postorder(tree[i]->right->label);
    cout << result;
}

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
        int index = current_value - 'A';
        tree[index]->label = current_value-'A';
        if(left_value != '.') tree[index]->left = tree[left_value-'A'];
        else tree[index]->left = NULL;
        if(right_value != '.') tree[index]->right = tree[right_value-'A'];
        else tree[index]->right = NULL;
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);

}