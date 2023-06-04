#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i +1;
    int right=2*i +2;
    if(left<n and arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n and arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2 -1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,n,0);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    priority_queue<int,vector<int>,greater<int>>minheap;
    priority_queue<int>maxheap;
    for(int i=0;i<n;i++){
        int marks;
        cin>>marks;
        arr.push_back(marks);
        minheap.push(marks);
        maxheap.push(marks);
    }
    cout<<"min marks:"<<minheap.top()<<endl;
    cout<<"max marks:"<<maxheap.top()<<endl;
    heapsort(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}