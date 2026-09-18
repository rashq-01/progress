#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename dataType>

class Graph{
    public:
        unordered_map<dataType,list<dataType>> adj;

        void addEdge(dataType u, dataType v, bool direction){
            //direction = 0----->undirected
            //direction = 1----->Directed

            //create an Edge from u to v
            adj[u].push_back(v);
            if(!direction){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"--> ";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }

        }
};

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;

    Graph<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter connection: ";
        cin>>u>>v;

        //Creating an unidirected graph
        g.addEdge(u,v,0);

        g.printAdjList();
    }
}