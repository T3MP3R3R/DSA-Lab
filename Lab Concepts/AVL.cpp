#include <iostream>
using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val){ data=val; left=right=NULL; height=1; }
};

int getHeight(AVLNode* node){ return node ? node->height : 0; }
int getBalance(AVLNode* node){ return node ? getHeight(node->left)-getHeight(node->right) : 0; }

AVLNode* rightRotate(AVLNode* y){
    AVLNode* x=y->left; AVLNode* T2=x->right;
    x->right=y; y->left=T2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}

AVLNode* leftRotate(AVLNode* x){
    AVLNode* y=x->right; AVLNode* T2=y->left;
    y->left=x; x->right=T2;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    return y;
}

AVLNode* minValueNode(AVLNode* node){
    AVLNode* current=node;
    while(current && current->left) current=current->left;
    return current;
}

AVLNode* insertAVL(AVLNode* root,int val){
    if(!root) return new AVLNode(val);
    if(val<root->data) root->left=insertAVL(root->left,val);
    else if(val>root->data) root->right=insertAVL(root->right,val);
    else return root;

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalance(root);

    // LL
    if(balance>1 && val<root->left->data) return rightRotate(root);
    // RR
    if(balance<-1 && val>root->right->data) return leftRotate(root);
    // LR
    if(balance>1 && val>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if(balance<-1 && val<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// AVL Deletion
AVLNode* deleteAVL(AVLNode* root,int key){
    if(!root) return root;
    if(key<root->data) root->left=deleteAVL(root->left,key);
    else if(key>root->data) root->right=deleteAVL(root->right,key);
    else{
        if(!root->left || !root->right){
            AVLNode* temp=root->left?root->left:root->right;
            if(!temp){ delete root; return NULL; }
            else { *root=*temp; delete temp; }
        }
        else{
            AVLNode* temp=minValueNode(root->right);
            root->data=temp->data;
            root->right=deleteAVL(root->right,temp->data);
        }
    }

    // Update height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalance(root);

    // Balance cases
    if(balance>1 && getBalance(root->left)>=0) return rightRotate(root); // LL
    if(balance>1 && getBalance(root->left)<0){ root->left=leftRotate(root->left); return rightRotate(root);} // LR
    if(balance<-1 && getBalance(root->right)<=0) return leftRotate(root); // RR
    if(balance<-1 && getBalance(root->right)>0){ root->right=rightRotate(root->right); return leftRotate(root);} // RL

    return root;
}

void inorder(AVLNode* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    AVLNode* root=NULL;
    root=insertAVL(root,10);
    root=insertAVL(root,20);
    root=insertAVL(root,30);
    root=insertAVL(root,40);
    root=insertAVL(root,50);
    root=insertAVL(root,25);

    cout<<"Inorder AVL before deletion: "; inorder(root); cout<<endl;

    root=deleteAVL(root,50);
    root=deleteAVL(root,40);

    cout<<"Inorder AVL after deletion: "; inorder(root); cout<<endl;

    return 0;
}