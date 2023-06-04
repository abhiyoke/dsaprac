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
        void inorder(node*);
        node* buildtree(int in[],int pre[],int st,int en,int n);
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
void binarytree::inorder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);

}
node* binarytree::buildtree(int in[],int pre[],int st,int en,int n){
    static int prein=0;
    if(st>en) return nullptr;
    node* temp=new node(pre[prein++]);
    if(st==en) return temp;
    int index=-1;
    for(int i=0;i<n;i++){
        if(in[i]==temp->data){
            index=i;
            break;
        }
    }
    temp->left=buildtree(in,pre,st,index-1,n);
    temp->right=buildtree(in,pre,index+1,en,n);
    return temp;
}
int main(){
    binarytree tree,tree1,clonetree;
    int choice,data;
    node* copy=nullptr;
    while(1){
        cout<<"1.insert"<<endl;
        cout<<"2.build tree "<<endl;
        cout<<"3.exit"<<endl;
        cout<<"enter your choice";
        cin>>choice;
        if(choice==1){
            cin>>data;
            tree.insert(data);
        }
        else if(choice==2){
            int in[11]={2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};
            int pre[11]={15,6,3,2,4,7,13,9,18,17,20};
            copy=tree.buildtree(in,pre,0,10,11);
            tree.inorder(copy);
        }
        
        
        else break;
    }
   return 0;
}