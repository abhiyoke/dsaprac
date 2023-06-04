#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int key;
        node* left;
        node* right;
        int height;
};
node* newnode(int key){
    node* ptr=new node();
    ptr->key=key;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->height=1;
    return ptr;
}
int height(node* N){
    if(N==NULL) return 0;
    return N->height;
}
int balancefac(node* N){
    if(N==NULL) return 0;
    return height(N->left)-height(N->right);
}
node* rightrotate(node* y){
    node* x=y->left;
    node* t2=x->right;

    x->right=y;
    y->left=t2;
    return x;
}
node* leftrotate(node* x){
    node* y=x->right;
    node* t2=y->left;

    y->left=x;
    x->right=t2;
    return y;
}
node* insert(node* n,int key){
    if(n==NULL) return newnode(key);
    if(key<n->key){
        n->left=insert(n->left,key);
    }
    else if(key>n->key){
        n->right=insert(n->right,key);
    }
    else return n;
    n->height=max(height(n->left),height(n->right))+1;
    int balance=balancefac(n);
    if(balance>1 && key<n->left->key){
        return rightrotate(n);
    }
    else if(balance<1 && key>n->right->key){
        return leftrotate(n);
    }
    else if(balance>1 && key>n->left->key){
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    else if(balance<1 && key<n->right->key){
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}
void level_order(node* root){
    if(root==NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}
int main(){
    node* root=NULL;
    int choice;
    int element;
    while(1){
        cout << "1. Insert " << endl;
		cout << "2. Level Order Traversal" << endl;
		cout << "3. Find Height of the Tree" << endl;
		cout << "4. EXIT" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Enter your choice:";
        cin>>choice;
        if(choice==1){
            cout<<"enter a element:";
            cin>>element;
            root=insert(root,element);//imp
        }
        else if(choice==2){
            level_order(root);
        }
        else if(choice==3){
            cout<<"height of a tree is:"<<height(root)<<endl;
        }
        else break;
    }
}