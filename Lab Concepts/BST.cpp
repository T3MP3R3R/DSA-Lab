#include <iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val){ data=val; left=right=NULL; }
};

BSTNode* insert(BSTNode* root,int val){
    if(!root) return new BSTNode(val);
    if(val<root->data) root->left = insert(root->left,val);
    else root->right = insert(root->right,val);
    return root;
}

BSTNode* minValueNode(BSTNode* node){
    BSTNode* current=node;
    while(current && current->left) current=current->left;
    return current;
}

BSTNode* deleteNode(BSTNode* root,int key){
    if(!root) return root;

    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else{
        if(!root->left){
            BSTNode* temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            BSTNode* temp=root->left;
            delete root;
            return temp;
        }
        // Node with two children
        BSTNode* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

void inorder(BSTNode* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    BSTNode* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);

    cout<<"Inorder before deletion: "; inorder(root); cout<<endl;

    root=deleteNode(root,20);
    root=deleteNode(root,30);
    root=deleteNode(root,50);

    cout<<"Inorder after deletion: "; inorder(root); cout<<endl;

    return 0;
}