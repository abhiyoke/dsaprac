#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int adj[][100],vector<int>&vis,int n){
   vis[node]=1;
   cout<<node<<" ";
   for(int i=0;i<n;i++){
    if(adj[node][i]==1 and vis[i]!=1){
        dfs(i,adj,vis,n);
    }
   }
   
}
void bfs(int node,int adj[][100],vector<int>&vis1,int n){
    queue<int>q;
    q.push(node);
    vis1[node]=1;
    while (!q.empty())
    {
        int node=q.front();
        vis1[node]=1;
        cout<<node<<" ";
        q.pop();
        for(int i=0;i<n;i++){
            if(!vis1[i] and adj[node][i]==1){
                q.push(i);
            }
        }
    }
   
}
int main(){
    cout<<"no. of nodes and edges";
    int n,m;
    cin>>n>>m;
    int adj[100][100]={0};
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int c=0;
    vector<int>vis(n,0);
    vector<int>vis1(n,0);
    cout<<"dfs traversal is:";
    for(int i=0;i<n;i++){
        if(!vis[i]){
        dfs(i,adj,vis,n);
        c++;}
    }
    cout<<endl;
    cout<<"bfs traversal is:";
    for(int i=0;i<n;i++){
        if(!vis1[i]){
            bfs(i,adj,vis,n);
           
        }
    }
    cout<<endl;
    cout<<c;
    return 0;
}