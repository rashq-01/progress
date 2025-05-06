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
    int V = 10;
    int E = 12;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{3,2},{2,1},{1,4},{4,2},{3,4},{5,6},{6,7},{7,5},{8,9}};

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