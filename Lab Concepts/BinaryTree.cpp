#include <iostream>
using namespace std;

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int val){ data=val; left=right=NULL; }
};

void preorder(BTNode* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BTNode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(BTNode* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    BTNode* root = new BTNode(1);
    root->left = new BTNode(2);
    root->right = new BTNode(3);
    root->left->left = new BTNode(4);
    root->left->right = new BTNode(5);

    cout<<"Preorder: "; preorder(root); cout<<endl;
    cout<<"Inorder: "; inorder(root); cout<<endl;
    cout<<"Postorder: "; postorder(root); cout<<endl;

    return 0;
}