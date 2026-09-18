#include <iostream>
#include <unordered_map>
#include <vector>
#include<queue>

using namespace std;

vector<int> topoSort(int V, vector<vector<int>> &edges){
    
    unordered_map<int,vector<int>> adj;
    vector<int> indegree(V,0);
    for(auto& ed : edges){
        adj[ed[0]].push_back(ed[1]);
        indegree[ed[1]]++;
    }

    vector<int> ans;
    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for(auto& v : adj[u]){
            indegree[v]--;
            
            if(indegree[v]==0)q.push(v);
        }
    }

    return ans;




}