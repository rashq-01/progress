#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;


void dfs(int node,vector<bool>&visited,unordered_map<int,list<int>> &adjList,vector<int> &component){
    component.push_back(node);
    visited[node] = true;


    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}


int main() {
    int V = 20;
    int E = 24;
    vector<vector<int>> edges = {
        {1,8},{1,15},{1,14},{2,13},{2,8},{3,13},{3,5},{4,6},{4,16},{4,0},{4,9},{5,18},{5,11},{5,17},{7,16},{7,14},{9,10},{10,17},{11,19},{11,18},{12,19},{12,13},{14,15},{17,18}
    };

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    cout << "Connected Components:\n";
    for (auto component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}