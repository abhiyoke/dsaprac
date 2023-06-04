#include <bits/stdc++.h>
using namespace std;
int main() {
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
    vector<int>dist(n,1e9);
    vector<int>parent(n);
    for(int i=0;i<n;i++) parent[i]=i;
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        int wt=it.first;
        int node=it.second;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it[0];
            int weight=it[1];
            if(dist[node]+wt<dist[adjnode]){
                dist[adjnode]=dist[node]+wt;
                pq.push({dist[adjnode],adjnode});
                parent[adjnode]=node;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<"shortest path from 0 to "<<i<<":";
        if(dist[i]==1e9) cout<<"no path"<<endl;
        else{
            vector<int>path;
            int node=i;
            while(node!=parent[node]){
                path.push_back(node);
                node=parent[node];
            }
            path.push_back(0);
            reverse(path.begin(),path.end());
            for(int i=0;i<path.size();i++){
                if(i==path.size()-1) cout<<path[i]<<endl;
                else cout<<path[i]<<"->";
            }
            
        }
    }

    return 0;
}