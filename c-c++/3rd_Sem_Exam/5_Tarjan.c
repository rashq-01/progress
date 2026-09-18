#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct
{
    int u, v;

} Edge;

int V, E;
int timeDFS = 0;
int disc[MAX], low[MAX], parent[MAX];
int stackTop = -1;
Edge stack[MAX * MAX];
int visited[MAX];

// Function to push Edge on stack
void pushEdge(int u, int v)
{
    stack[++stackTop].u = u;
    stack[stackTop].v = v;
}

// Function to print Biconnected Component
void printBCC(int u, int v)
{
    printf("Biconnected Components : ");
    while (1)
    {
        Edge e = stack[stackTop--];
        printf("(%d-%d) ", e.u, e.v);
        if (e.u == u && e.v == v)
            break;
    }
    printf("\n");
}

// DFS to find Biconnected Componects
void DFS(int u, int graph[MAX][MAX])
{
    int children = 0;
    int v;
    disc[u] = low[u] = ++timeDFS;

    for (v = 0; v < V; v++)
    {
        if (graph[u][v])
        {
            if (disc[v] == -1)
            {
                children++;
                parent[v] = u;
                pushEdge(u, v);
                DFS(v, graph);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u]))
                {
                    printBCC(u, v);
                }
                else if (v != parent[u] && disc[v] > disc[u])
                {
                    low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
                    pushEdge(u, v);
                }
            }
        }
    }
}

void main()
{
    int graph[MAX][MAX] = {0};
    int i, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v) with vertices numbered from 0 to %d:\n", V - 1);
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    // Initialize arrays
    for (i = 0; i < V; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }
    printf("\nBiconnected Components in the graph:\n");
    for (i = 0; i < V; i++)
    {
        if (disc[i] == -1)
            DFS(i, graph);
        // Print remaining edges if any
        if (stackTop != -1)
        {
            printBCC(stack[0].u, stack[0].v);
        }
    }
}