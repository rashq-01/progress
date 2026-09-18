#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

void DFS(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,stack<int>& st){
    visited[u] = true;

    for(auto& v:adj[u]){
        if(!visited[v]) DFS(v,adj,visited,st);
    }
    st.push(u);
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>> adj;
    for(auto& ed : edges){
        adj[ed[0]].push_back(ed[1]);
    }
    // code here
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]) DFS(i,adj,visited,st);
    }
    
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}