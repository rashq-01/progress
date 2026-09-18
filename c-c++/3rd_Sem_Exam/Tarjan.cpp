#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


void dfs(int node,int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis){
    
    vis[node] = true;
    disc[node] = low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node] = min(low[node],low[nbr]);


            //Check edge is bridge 
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            low[node] = min(low[node],disc[nbr]);
        }
    }

}



vector<vector<int>> findBridge(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;

    unordered_map<int,bool> vis;
    vector<vector<int>> result;

    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1;
    }

    //dfs
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }

    return result;


}

// ----------------------------------------------------
//                 TEST CODE (main)
// ----------------------------------------------------
int main(){
    int v = 5;  
    int e = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    vector<vector<int>> bridges = findBridge(edges, v, e);

    cout << "Bridges in the graph:\n";
    for(auto &b : bridges){
        cout << b[0] << " -- " << b[1] << endl;
    }

    return 0;
}