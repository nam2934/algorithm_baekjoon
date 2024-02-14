#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Node {
    char elem;
    Node* left;
    Node* right;
};

int N;
vector<Node*> tree;

void preorder(Node* node){
    if(node == NULL) return;
    cout << node->elem;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node == NULL) return;
    inorder(node->left);
    cout << node->elem;
    inorder(node->right);
}

void postorder(Node* node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->elem;
}

int main(){
    cin >> N;
    tree = vector<Node*>(N);
    for(int i=0; i<N; i++) tree[i] = new Node();
    for(int i=0; i<N; i++) tree[i]->elem = 'A' + i;
    for(int i=0; i<N; i++){
        char s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if(s2 == '.')  tree[s1-'A']->left = NULL;
        else tree[s1-'A']->left = tree[s2-'A'];
        if(s3 == '.')  tree[s1-'A']->right = NULL;
        else tree[s1-'A']->right = tree[s3-'A'];
    }        
    preorder(tree[0]);
    cout << "\n";
    inorder(tree[0]);
    cout << "\n";
    postorder(tree[0]);
    cout << "\n";
}