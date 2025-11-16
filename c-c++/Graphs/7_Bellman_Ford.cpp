#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> bellmanFord(vector<vector<int>>& edges,int V, int S){
    vector<int> dist(V,INT_MAX);
    dist[S] = 0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //Nth relaxation to check negative cycle
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
            return {-1};
        }
    }

    return dist;

}


int main() {
    // ============================
    // 🟢 TEST CASE 1: Simple Graph (No Negative Cycle)
    // ============================
    /*int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int S = 0; // Source
    */
    // ============================
    // 🟡 TEST CASE 2: Negative Edge (Cashback Example, No Cycle)
    /*
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, -4},
        {2, 1, 2}
    };
    int S = 0;
    */
    
    // ============================
    // 🔴 TEST CASE 3: Negative Cycle
    /*
    int V = 3;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 0, -1}
    };
    int S = 0;
    */

    // ============================
    // 🟢 TEST CASE 4: Positive Weights Only
    /*
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {2, 3, 4},
        {1, 3, 7}
    };
    int S = 0;
    */

    // ============================
    // 🟡 TEST CASE 5: Disconnected Graph
    
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 2, 3}
    };
    int S = 0;
    

    // ============================

    vector<int> dist = bellmanFord(edges, V, S);

    if (dist.size() == 1 && dist[0] == -1) {
        cout << "⚠️ Negative Cycle Detected!" << endl;
    } else {
        cout << "Shortest distances from source " << S << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            if (dist[i] == INT_MAX)
                cout << "INF (Unreachable)";
            else
                cout << dist[i];
            cout << endl;
        }
    }

    return 0;
}
