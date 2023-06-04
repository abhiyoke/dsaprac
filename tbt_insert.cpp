#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        bool rightt;
};
node* newnode(int key){
    node* temp=new node();
    temp->data=key;
    temp->left=nullptr;
    temp->right=nullptr;
    temp->rightt=false;
    return temp;
}
node* insert(node* root,int key){
    if(root==nullptr) return newnode(key);
    else if(root->data>key){
        node* leftc=insert(root->left,key);
        root->left=leftc;
        leftc->right=root;
        leftc->rightt=true;
    }
    else if(root->data<key){
        if(root->rightt==true){
            node* temp=newnode(key);
            temp->right=root->right;
            temp->rightt=true;
            root->right=temp;
            root->rightt=false;
        }
        else{
            root->right=insert(root->right,key);
        }
    }
    return root;
}
void inorder(node* root){
  node* curr=root;
    while(curr!=nullptr){
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        cout<<curr->data<<" ";
        while(curr->rightt and curr->right!=nullptr){
            curr=curr->right;
            cout<<curr->data<<" ";
        }
        curr=curr->right;
    }
}
int main(){
    node* root=nullptr;
    int choice,key;
    while(1){
            cout << "\nMENU\n";
            cout << "1. Insert a new node\n";
            cout << "2. Inorder traversal\n";
            cout << "3. Exit\n";
            cin>>choice;
            if(choice==1){
                cin>>key;
                root=insert(root,key);
            }
            else{
                inorder(root);
                cout<<endl;
            }
    }
}