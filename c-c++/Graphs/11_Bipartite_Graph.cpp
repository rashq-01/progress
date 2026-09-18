#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u,unordered_map<int,vector<int>>& adj,vector<int>& color, int currColor){
        color[u] = currColor;

        for(auto& v : adj[u]){
            if(color[v] == currColor)return false;
            if(color[v]==-1 && !dfs(v,adj,color,1-currColor))return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<graph.size();i++){
            for(auto& v : graph[i]){
                adj[i].push_back(v);
            }
        }

        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i] == -1 && !dfs(i,adj,color,1))return false;
        }

        return true;
    }
};