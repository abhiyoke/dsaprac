#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n,e;
    cout<<"no. of nodes and edges";
    cin>>n>>e;
    vector<vector<int>>adj[n];
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
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<int>parent(n,-1);
    vector<vector<int>>mst(n-1);
    int sum=0;
    int c=0;
    vector<int>vis(n,0);
    while(!pq.empty()){
        auto it=pq.top();
        int wt=it.first;
        int node=it.second;
        pq.pop();
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        if(parent[node]!=-1){
            mst[c].push_back(parent[node]);
            mst[c].push_back(node);
              mst[c].push_back(wt);
           c++;
        }
        for(auto it:adj[node]){
            int adjnode=it[0];
            int weight=it[1];
            if(!vis[adjnode]){
            pq.push({weight,adjnode});
            parent[adjnode]=node; 
            }
        }
    }
    cout<<"mst is:"<<sum<<endl;
    cout<<"paths included are"<<endl;
    for(int i=0;i<mst.size();i++){
        cout<<mst[i][0]<<"->"<<mst[i][1]<<"="<<mst[i][2]<<endl;
    }
    return 0;
}
