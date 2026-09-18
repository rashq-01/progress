#include<stdio.h>
#include<stdlib.h>

#define MAX 20

//Queue for BFS
int queue[MAX],front=-1,rear=-1,i;
int visited[MAX];

void enqueue(int v){
    if(rear==MAX-1)return;
    if(front==-1)front=0;
    queue[++rear] = v;
}

int dequeue(){
    if(front==-1 || front>rear)return -1;
    return queue[front++];
}

//BFS using adjacency Matrix
void BFS_matrix(int adj[MAX][MAX],int n, int start){
    for(int i=0;i<n;i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS (Adjacency MAtrix) : ");
    while(front<=rear){
        int v = dequeue();
        printf("%d ",v);

        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");

}

void DFS_matrix(int adj[MAX][MAX],int n, int v){
    printf("%d ",v);
    visited[v] = 1;

    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && !visited[i]){
            DFS_matrix(adj,n,i);
        }
    }
}


void main(){
    int n,edges,u,v;
    int adj[MAX][MAX];
    int start;
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }

    printf("\nEnter number of Edges : ");
    scanf("%d",&edges);

    printf("Enter Edges (u,v) : ");
    for(int i=0;i<edges;i++){
        scanf("%d%d",&u,&v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("\nEnter starting Vertex : ");
    scanf("%d",&start);

    front = rear = -1;
    BFS_matrix(adj,n,start);


    for(int i=0;i<n;i++)visited[i]=0;
    printf("DFS (Adjacency Matrix) : ");
    DFS_matrix(adj,n,start);
    printf("\n");
    


}