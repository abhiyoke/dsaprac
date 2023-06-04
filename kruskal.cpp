#include<bits/stdc++.h>
using namespace std;
class disjoint{
 public:
    vector<int>parent,size;
    disjoint(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ult_u=findupar(u);
        int ult_v=findupar(v);
        if(ult_u==ult_v) return;
        else if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
             parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};
int main(){
    cout<<"no. of nodes and edges";
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj[n];    
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>t,t1;
        t.push_back(v);
        t.push_back(w);
        adj[u].push_back(t);
         t1.push_back(u);
        t1.push_back(w);
        adj[v].push_back(t1);
        edges.push_back({w,{u,v}});
        edges.push_back({w,{v,u}});
    }
    

    /*for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            int wt=it[1];
            int adjnode=it[0];
            int node=i;
            edges.push_back({wt,{node,adjnode}});
        }
    }
    */
    sort(edges.begin(),edges.end());
    disjoint ds(n);
    int mst=0;
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findupar(u)!=ds.findupar(v)){
                mst+=wt;
                ds.unionbysize(u,v);
                
        }
    }
    cout<<mst;
    return 0;
}