#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>  // For queue
#include <utility> // For pair
using namespace std;



void prepAdjList(unordered_map<int,list<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool> &visited,vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //Store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbour of frontNode
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex,vector<pair<int,int>> edges){
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepAdjList(adjList,edges);


    //Treverse all components of a graph

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}


int main() {
    int v = 20;
    vector<pair<int, int>> edges = {
        {1,8},{1,15},{1,14},{2,13},{2,8},{3,13},{3,5},{4,6},{4,16},{4,0},{4,9},{5,18},{5,11},{5,17},{7,16},{7,14},{9,10},{10,17},{11,19},{11,18},{12,19},{12,13},{14,15},{17,18}
    };

    vector<int> result = BFS(v, edges);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}