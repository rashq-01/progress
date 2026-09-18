#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<climits>
#include<list>
#include<set>
using namespace std;


vector<int> dijkstraAlgo(vector<vector<int>> &vec, int vertices, int edges, int source){
    //Create adjacency List
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];


        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Creation of distance array with infinite value initially

    vector<int> dist(vertices,INT_MAX);

    set<pair<int,int>> st;
    
    dist[source] = 0;

    st.insert(make_pair(0,source));

    while(!st.empty()){
        //Fetch top record
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now
        st.erase(st.begin());

        //Traverse on neighbours
        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                //if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }
                //distance update
                dist[neighbour.first] = nodeDistance+neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    

    return dist;


}

int main(){
    vector<vector<int>> vec = {
    {0,1,2},{1,2,3},{2,3,5},{3,4,2},{4,5,4},{5,6,6},
    {6,7,7},{7,8,3},{8,9,2},{9,10,5},{10,11,1},
    {11,12,8},{12,13,4},{13,14,9},{14,15,10},{15,16,2},
    {16,17,3},{17,18,1},{18,19,6},
    {2,7,5},{4,10,8},{8,15,12}
    };
    int vertices = 20;
    int edges = 22;
    int source = 0;


    vector<int> result = dijkstraAlgo(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for(int i = 0; i < vertices; i++){
        if(result[i] == INT_MAX) cout << "Node " << i << " → Unreachable\n";
        else cout << "Node " << i << " → " << result[i] << "\n";
    }

    return 0;
}
