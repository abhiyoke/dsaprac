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
        void preorder();
        node* mirror(node*);
        void preorder(node*);
        int height(node*);
};
void binarytree::preorder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
int binarytree::height(node* root){
    if(root==nullptr) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
void binarytree::insert(int value){
    node* ptr=new node(value);
    if(root==nullptr) root=ptr;
    else{
        node* temp=root;
        if(temp->data>value){
            while(1){
                if(temp->left==nullptr){
                    temp->left=ptr;
                    break;
                }
                temp=temp->left;
            }
        }
        else if(temp->data<value){
              while(1){
                if(temp->right==nullptr){
                    temp->right=ptr;
                    break;
                }
                temp=temp->right;
            }
        }
    } 
}
void binarytree::preorder(){
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node* ptr=st.top();
        cout<<ptr->data<<" ";
        st.pop();
        if(ptr->right!=nullptr)
        st.push(ptr->right);
        if(ptr->left!=nullptr)
        st.push(ptr->left);
    }
}
node* binarytree::mirror(node* root){
    if(root==nullptr) return nullptr;
    node* ptr=new node(root->data);
    node* x=mirror(root->left);
    node* y=mirror(root->right);
    ptr->left=y;
    ptr->right=x;
    return ptr;
}
int main(){
    binarytree tree,tree1,clonetree;
    int choice,data;
    node* mirro=nullptr;
    while(1){
        cout<<"1.insert"<<endl;
        cout<<"2.preorder"<<endl;
        cout<<"3.mirror"<<endl;
        cout<<"4.height"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter your choice";
        cin>>choice;
        if(choice==1){
            cin>>data;
            tree.insert(data);
        }
        else if(choice==2){
            tree.preorder();
        }
        else if(choice==3){
            mirro=tree.mirror(tree.getroot());
            tree.preorder(mirro);
        }
        else if(choice==4){
            int h=tree.height(tree.getroot());
            cout<<"height:"<<h<<endl;
        }
        else break;
    }
   return 0;
}