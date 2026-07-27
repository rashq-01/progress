#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int u){
        if(u == parent[u])return u;
        
        return parent[u] = find(parent[u]);
    }
    
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y)return;
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    bool isCycle(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        
        parent.resize(V);
        rank.resize(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int u=0;u<V;u++){
            for(auto& v : adj[u]){
                if(u<=v){
                int parent_u = find(u);
                    int parent_v = find(v);
                    
                    if(parent_u == parent_v)return true;
                    
                    
                    Union(u,v);
                }
            }
        }
        return false;
        
    }
};

int main(){


    return 0;
}