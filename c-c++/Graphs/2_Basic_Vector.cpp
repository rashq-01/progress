#include<iostream>
#include<vector>
using namespace std;

class Graph{
        int V; //Vertices;
        vector<vector<int>> adj;
    public:
        Graph(int vertices){
            this->V = vertices;
            adj.resize(vertices);
        }

        void addEdge(int u, int v,bool direction){
            //direction = 0 -----> Undirected
            //direction = 1 -----> Directed
            adj[u].push_back(v);
            if(!direction){
                adj[v].push_back(u);
            }

        }

        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<"Node "<<i<<": ";
                for(int j :adj[i]){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
    
};

int main(){
    Graph g(5);
    g.addEdge(0,1,0);
    g.addEdge(0,4,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(1,4,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    cout<<endl;
    g.printGraph();
}