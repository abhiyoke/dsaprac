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
        
        if(table[index].data%10==data%10){
            int last=index;
            while(table[index].data!=-1){
                if(table[index].data%10==data%10) last=index;
                index++;
            }
            table[index].data=data;
            table[last].link=index;
            
        }
        else{
            int value=table[index].data;
            int last=table[index].link;
            int k=index;
            table[index].data=data;
            table[index].link=-1;
            while(table[index].data!=-1){
                index++;
                index=index%10;
            }
            table[index].data=value;
            table[index].link=last;
            for(int i=0;i<10;i++){
                if(table[i].link==k){
                    table[i].link=index;
                    break;
                }
            }
        }
    }
}
void display(hash1 table[]){
    cout<<"index"<<" "<<"data"<<" "<<"link"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" "<<table[i].data<<" "<<table[i].link<<endl;
    }
}
    



int main(){
    hash1 table[10];
    for(int i=0;i<7;i++)
    insert(table);
    display(table);
   

}