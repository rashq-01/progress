#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;




bool isCyclic(int V, vector<vector<int>> &edges){

    unordered_map<int,vector<int>> adj;
    vector<int> indegree(V,0);

    for(auto& ed : edges){
        adj[ed[0]].push_back(ed[1]);
        indegree[ed[1]]++;
    }

    queue<int> q;
    int count = 0;

    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        count++;

        for(auto& v : adj[u]){
            indegree[v]--;

            if(indegree[v]==0){
                q.push(v);
            }
        }
    }

    return count!=V;
        
}



int main(){


    return 0;
}