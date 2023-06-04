#include<bits/stdc++.h>
using namespace std;
class hash1{
   public:
        int data;
        int link;
        hash1(){
            data=-1;
            link=-1;
        }
};
void insert(hash1 table[]){
     int data;
     cin>>data;
    int index=data%10;
    if(table[index].data==-1){
        table[index].data=data;
    }
    else{
            int last=index;
            while(table[index].data!=-1){
                if(table[index].data%10==data%10) last=index;
                index++;
            }
            table[index].data=data;
            table[last].link=index;
            
        }
        
    
}
void display(hash1 table[]){
    cout<<"index"<<" "<<"data"<<" "<<"link"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" "<<table[i].data<<" "<<table[i].link<<endl;
    }
}
void search(hash1 table[],int data){
    for(int i=0;i<10;i++){
        if(table[i].data==data){
            cout<<"data found"<<endl;
            return;
        }
    }
    cout<<"data not found"<<endl;
    return ;
}
    



int main(){
    hash1 table[10];
    int choice;
    int data;
    while(1){
        cout<<"1.insert"<<endl;
        cout<<"2.search"<<endl;
        cout<<"3.display"<<endl;
        cout<<"Enter your choice";
        cin>>choice;
        if(choice==1){
            insert(table);
        }
        else if(choice==2){
            cin>>data;
            search(table,data);
        }
        else if(choice==3){
            display(table);
        }
        else break;
    }
    return 0;
}