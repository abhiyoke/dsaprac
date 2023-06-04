#include<bits/stdc++.h>
using namespace std;
void topo_sort(vector<int>adj[],int n){
    int indegree[n]={0};
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
    }

int main(){
    cout<<"no. of nodes and edges";
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    topo_sort(adj,n);
return 0;
}