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
        void inorder();
        node* delete_node(node*,int);
};
void binarytree::insert(int key){
    node* ptr=new node(key);
    if(root==nullptr) root=ptr;
    else{
        node* temp=root;
        if(temp->data>key){
            while(1){
                if(temp->left==nullptr){
                    temp->left=ptr;
                    break;
                }
                temp=temp->left;
            }
        }
        else if(temp->data<key){
              while(1){
                if(temp->right==nullptr){
                    temp->right=ptr;
                    break;
                }
                temp=temp->right;
            }
        }
        else return;
    }
}
node* binarytree::delete_node(node* root,int key){
    if(root==nullptr) return nullptr;
    if(root->data==key && root->left==nullptr && root->right==nullptr){
        delete root;
        return nullptr;
    }
    if(root->data>key){
        root->left=delete_node(root->left,key);
        return root;
    }
    else if(root->data<key){
        root->right=delete_node(root->right,key);
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
        else{
            succ_p->right=succ->right;
        }
        root->data=succ->data;
        delete succ;
        return root;
    }
}
void binarytree::inorder(){
    node* temp=root;
    stack<node*>st;
    while(1){
        if(temp!=nullptr){
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
             temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
               temp=temp->right;
        }
    }
}
int main(){
    binarytree tree,tree1,clonetree;
    int choice,data;
    node* copy=nullptr;
    while(1){
        cout<<"1.insert"<<endl;
        cout<<"2.inorder"<<endl;
        cout<<"3.delete "<<endl;
        cout<<"4.exit"<<endl;
        cout<<"enter your choice";
        cin>>choice;
        if(choice==1){
            cin>>data;
            tree.insert(data);
        }
        else if(choice==2){
            tree.inorder();
        }
        
        else if(choice==3){
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