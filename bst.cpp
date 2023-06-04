#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node(){
            this->left=NULL;
            this->right=NULL;
        }
        node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
        friend class binary_tree;
};
class binary_tree{
    public:
        node* root;
        binary_tree(){
                root=NULL;
        }
        node* getroot(){
                return root;
        }
        void insert(int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        void iter_preorder();
        void iter_postorder();
        void iter_inorder();
        node* delete_node(node*,int);
        node* clone(node*);
        node* mirror_image(node*);
       node* buildtree(int in[] ,int pre[] ,int st ,int en);
       bool check_equal(node* ,node* );
};
void binary_tree::insert(int key){
    node* ptr=new node(key);
    if(root==NULL) root=ptr;
    else{
        node* temp=root;
        while(1){
        if(temp->data>key){
            if(temp->left==NULL){
                temp->left=ptr;
                break;
            }
                temp=temp->left;
        }
        else if(temp->data<key){
                if(temp->right==NULL){
                    temp->right=ptr;
                    break;
                }
                temp=temp->right;
        }
        }
    }
}
void binary_tree::preorder(node* root){
    if(root!=NULL) {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);}
}
void binary_tree::inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
}
void binary_tree::postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* binary_tree::delete_node(node* root,int key){
    if(root==NULL) return root ;
     if(root->data==key && root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
     }
     if(root->data>key){
        root->left=delete_node(root->left,key);
        return root;
     }
     else if(root->data<key){
        root->right=delete_node(root->right,key);
        return root;
     }
     if(root->left==NULL){
        node* temp=root->right;
        root->data=temp->data;
        root->left=temp->left;
        root->right=temp->right;
        delete temp;
        return root;
     }
     else if(root->right==NULL){
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
        while(succ->left!=NULL){
            succ_p=succ;
            succ=succ->left;
        }
        if(succ_p!=root) succ_p->left=succ->right;
        else succ_p->right=succ->right;
        root->data=succ->data;
        delete succ;
        return root;
     }
}

void binary_tree::iter_preorder(){
    if(root==NULL) return;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node* temp=st.top();
        cout<<temp->data<<" ";
        st.pop();
        if(temp->right!=NULL)st.push(temp->right);
        if(temp->left!=NULL)st.push(temp->left);
    }
}
void binary_tree::iter_postorder(){
    if(root==NULL) return;
    stack<node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        node* temp=st1.top();
        st2.push(temp);
        st1.pop();
        if(temp->right!=NULL)st1.push(temp->right);
        if(temp->left!=NULL)st1.push(temp->left);
    }
    while(!st2.empty()){
        node* temp1=st2.top();
        cout<<temp1->data<<" ";
        st2.pop();
    }
}
void binary_tree::iter_inorder(){
    if(root==NULL) return;
    stack<node*>st;
    node* curr=root;
    while(1){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            if(st.empty()) break;
            cout<<st.top()->data<<" ";
            st.pop();
         
               curr->right;
            }
        }
    }

node* binary_tree::clone(node* root){
    if(root==NULL) return NULL;
    else{
        node* ptr=new node(root->data);
        node* x=clone(root->left);
        node* y=clone(root->right);
        ptr->left=x;
        ptr->right=y;
        delete root;
        return ptr;
    }
}
node* binary_tree::mirror_image(node* root){
    if(root==NULL) return NULL;
    else{
        node* ptr=new node(root->data);
        node* x=mirror_image(root->left);
        node* y=mirror_image(root->right);
        ptr->left=y;
        ptr->right=x;
        delete root;
        return ptr;
    }
}
node* binary_tree::buildtree(int in[],int pre[],int st,int en){
        static int prein=0;
        if(st>en) return NULL;
        node* temp=new node(pre[prein++]);
        if(st==en) return temp;
        int index=0;
        for(int i=0;i<3;i++){
            if(in[i]==temp->data){
                index=i;
                break;
            }
        }
        temp->left=buildtree(in,pre,st,index-1);
        temp->right=buildtree(in,pre,index+1,en);
        return temp;
}
bool binary_tree::check_equal(node* root1,node* root2){
    if(root1==root2) return 1;
    else if(root1!=NULL and root2==NULL) return 0;
    else if(root1==NULL and root2!=NULL) return 0;
    else{
        if(root1->data==root2->data){
            bool x=check_equal(root1->left,root2->left);
            if(x==1){
                bool y=check_equal(root1->right,root2->right);
                if(y==1) return 1;
            }
        }
        return 0;
    }
}
 int main(){
 binary_tree tree,tree1;
 node* copy=NULL;
 node* mirror=NULL;
    int key;
    for(int i = 0; i < 5 ;i++) {
        cin >> key;
        tree.insert(key);
    }
   /* tree.delete_node(tree.getroot(), 1);
     tree.delete_node(tree.getroot(), 2);
      tree.delete_node(tree.getroot(), 3);
       tree.delete_node(tree.getroot(), 4);
        node* xt=tree.delete_node(tree.getroot(), 5);
        if(xt==NULL) tree=tree1;*/
       //mirror = tree.mirror_image(tree.getroot());
	   //tree.inorder(mirror);
       mirror=tree.mirror_image(tree.root);
      int pre[3]={1,2,3};
       int in[3]={2,1,3};
       copy=tree.buildtree(in,pre,0,2);
       tree.inorder(copy);
       bool x=tree.check_equal(copy,mirror);
       if(x==1) cout<<"equal";
       else cout<<"not";
    cout<<endl;
    
    return 0;
}