#include<bits/stdc++.h>

using namespace std;


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        set<pair<int,int>> s;
        vector<int> dest(V,INT_MAX);
        
        s.insert({0,src});
        
        dest[src] = 0;
        
        while(!s.empty()){
            auto topNode = *s.begin();
            int currDist = topNode.first;
            
            s.erase(s.begin());
            
            for(auto& nbr : adj[topNode.second]){
                auto v = nbr.first;
                int wt = nbr.second;
                
                if(currDist+wt < dest[v]){
                    s.erase({dest[v],v});
                    
                    dest[v] = currDist+wt;
                    s.insert({currDist+wt,v});
                }
            }
        }
        
        return dest;
    }
};


int main(){


    return 0;
}