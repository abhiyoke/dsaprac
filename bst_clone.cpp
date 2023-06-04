#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int value){
            this->data=value;
            this->left=nullptr;
            this->right=nullptr;
        }
        friend class binarytree;
};
class binarytree{
    public:
        node* root;
        binarytree(){
                root=nullptr;
        }
        node* getroot(){
            return root;
        }
        void insert(int);
        void preorder(node*);
        node* delete_node(node*,int);
        node* clone(node*);
};
void binarytree::insert(int value){
    node* ptr=new node(value);
    if(root==nullptr){
        root=ptr;
        return ;
    }
    node* temp=root;
    if(temp->data>value){
        while(1){
        if(temp->left==nullptr){
            temp->left=ptr;
            break;
        }
         temp= temp->left;
        }
    }
    else if( temp->data<value){
        while(1){
         if( temp->right==nullptr){
              temp->right=ptr;
              break;
        }
         temp= temp->right;
        }
    }
}
void binarytree::preorder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
node* binarytree::delete_node(node* root,int value){
    if(root==nullptr) return root;
    if(root->data==value && root->left==nullptr && root->right==nullptr){
        delete root;
        return nullptr;
    }
    if(root->data>value){
        root->left=delete_node(root->left,value);
        return root;
    }
    else if(root->data<value){
        root->right=delete_node(root->right,value);
        return root;
    }
    if(root->left==nullptr){
        node* temp=root->right;
        root->data=temp->data;
        root->left=temp->left;
        root->right=temp->right;
        delete temp;
        return root;
    }
    else if(root->right==nullptr){
        node* temp=root->left;
        root->data=temp->data;
        root->left=temp->left;
         root->right=temp->right;
        delete temp;
        return root;
    }
    else{
        node* succ_p=root;
        node* succ=root->right;
        while(succ->left!=nullptr){
            succ_p=succ;
            succ=succ->left;
        }
        if(succ_p!=root){
            succ_p->left=succ->right;
        }
        else succ_p->right=succ->right;
        root->data=succ->data;
        delete succ;
        return root;
    }
}
node* binarytree::clone(node* root){
    if(root==nullptr) return nullptr;
    node* ptr=new node(root->data);
    node* x=clone(root->left);
    node* y=clone(root->right);
    ptr->left=x;
    ptr->right=y;
    return ptr;
}
int main(){
    binarytree tree,tree1,clonetree;
    int choice,data;
    node* copy=nullptr;
    while(1){
        cout<<"1.insert"<<endl;
        cout<<"2.preorder"<<endl;
        cout<<"3.clone"<<endl;
        cout<<"4.delete "<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter your choice";
        cin>>choice;
        if(choice==1){
            cin>>data;
            tree.insert(data);
        }
        else if(choice==2){
            tree.preorder(tree.getroot());
        }
        else if(choice==3){
            copy=tree.clone(tree.getroot());
            tree.preorder(copy);
        }
        else if(choice==4){
            cin>>data;
            node* xt=tree.delete_node(tree.getroot(),data);
            if(xt==nullptr) {
                tree=tree1;
                cout<<"tree is empty"<<endl;
            }
        }
        else break;
    }
   return 0;
}