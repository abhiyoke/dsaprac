#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        string wd;
        node* next;
        node(string word){
            this->wd=word;
            next=NULL;
        }
        friend class sep_chaining;
};
class sep_chaining{
    public:
        node* hasht[23];
        sep_chaining(){
        for(int i=0;i<23;i++) hasht[i]=NULL;
        }
        int get_index(string);
        void insert(string);
        void search(string);
        void display();
};
int sep_chaining::get_index(string wd){
    int n=wd.size()-1;
    int s=0;
    for(int i=0;i<n;i++){
        s+=(int)wd[i];
    }
    return s%23;
}
void sep_chaining::insert(string wd){
    node* ptr=new node(wd);
    int index=get_index(wd);
    if(hasht[index]==NULL){
        hasht[index]=ptr;
    }
    else{
        ptr->next=hasht[index];
        hasht[index]=ptr;
    }
}
void sep_chaining::search(string wd){
    int index=get_index(wd);
    if(hasht[index]==NULL){
        cout<<"word is not found"<<endl;
        return;
    }
    else{
        node* temp=hasht[index];
        while(temp!=NULL){
            if(temp->wd==wd){
                cout<<"word is found"<<endl;
                return;
            }
            else temp=temp->next;
        }
        cout<<"word is not found"<<endl;
        return;
    }
}
void sep_chaining::display(){
        cout<<"index"<<" "<<"word"<<endl;
        for(int i=0;i<23;i++){
            if(hasht[i]==NULL){
                cout<<i<<" "<<" "<<endl;
            }
            else{
                node* temp=hasht[i];
                cout<<i<<" ";
                while(temp!=NULL){
                    cout<<temp->wd<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
            
        }
}
int main(){
    sep_chaining a;
    string word;
    ifstream in;
    ofstream out;
    in.open("word.txt");
    while(!in.eof()){
        in>>word;
        a.insert(word);
    }
    in.close();
    while(1){
        int choice;
        cout<<"1.Search for word"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.exit"<<endl;
        cout<<"Enter your choice";
        cin>>choice;
        if(choice==1){
            cout<<"Enter word to be searched";
             cin>>word;
             a.search(word);
        }
        else if(choice==2){
            a.display();
        }
        else break;
    }
   
}