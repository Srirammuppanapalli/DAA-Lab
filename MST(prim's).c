Aim:
To implement Prim’s Algorithm in C to find the Minimum Spanning Tree (MST) of a graph using a greedy approach and adjacency matrix representation.

Program:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5   // Number of vertices
#define E 6   // (Not used here, but defined)

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;

    // Loop through all vertices
    for (int i = 0; i < V; i++)
    {
        // Select the unvisited vertex with smallest key value
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Start from vertex 1 (since 0 is root)
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores MST
    int key[V];      // Key values (minimum edge weight)
    int visited[V];  // Track visited vertices

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from first vertex
    key[0] = 0;
    parent[0] = -1;  // Root node has no parent

    // MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex not yet included
        int u = minKey(key, visited);

        visited[u] = 1;  // Mark vertex as included in MST

        // Update key and parent of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Check:
            // 1. Edge exists
            // 2. Vertex not yet included
            // 3. Weight is smaller than current key
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Call Prim's Algorithm
    primMST(graph);

    return 0;
}

Output:

Prim's MST:
Edge 	Weight
0 - 1 	2
0 - 2 	3
1 - 3 	3
3 - 4 	2
Total Cost = 10
