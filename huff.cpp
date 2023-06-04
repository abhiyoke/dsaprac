#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
class Node{
    public:
        char ch;
        int freq;
        Node* left;
        Node* right;  
};
Node* getnode(char ch,int freq,Node* left,Node* right){
    Node* node=new Node();
    node->ch=ch;
    node->freq=freq;
    node->left=left;
    node->right=right;
    return node;
}
Node* buildtree(string text){
    unordered_map<char,int>freq;
    for(char c:text){
        freq[c]++;
    }
    
priority_queue<Node*,vector<Node*>,greater<Node*>>pq;
for(auto it:freq){
        pq.push(getnode(it.first,it.second,nullptr,nullptr));
    }
while(pq.size()>1){
    Node* left=pq.top();
    pq.pop();
    Node* right=pq.top();
    pq.pop();
    int sum=left->freq+right->freq;
    pq.push(getnode('\0',sum,left,right));
}
return pq.top();
}
void gethuffmancode(Node* root,string code,unordered_map<char,string>&huffmancode){
    if(root==NULL) return ;
    if(root->left==NULL and root->right==NULL) huffmancode[root->ch]=code;
    gethuffmancode(root->left,code+'0',huffmancode);
    gethuffmancode(root->right,code+'1',huffmancode);
}
string encoding(string text,unordered_map<char,string>&huffmancode){
    string encoded="";
    for(auto it:text){
        encoded+=huffmancode[it];
    }
    return encoded;
}
string decoding(Node* root,string encoded){
    Node* curr=root;
    string decoded="";
    for(char bit:encoded){
        if(bit=='0'){
            curr=curr->left;
        }
        else curr=curr->right;
        if(curr->left==nullptr and curr->right==nullptr){
            decoded+=curr->ch;
            curr=root;
        }
    }
    return decoded;
}
int main(){
    string text;
    cout<<"Enter a string:";
    getline(cin, text);
    Node* root=buildtree(text);
    unordered_map<char,string>huffmancode;
    gethuffmancode(root,"",huffmancode);
    int choice;
    do {
        cout << "1. Encode\n2. Decode\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string encodedText = encoding(text, huffmancode);
            cout << "Encoded text: " << encodedText << endl;
        } else if (choice == 2) {
            string bitSequence;
            cout << "Enter the bit sequence to be decoded: ";
            cin >> bitSequence;
            string decodedText = decoding(root,bitSequence);
            cout << "Decoded text: " << decodedText << endl;
        }
    } while (choice != 3);

}