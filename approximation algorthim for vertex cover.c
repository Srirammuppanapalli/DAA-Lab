Aim:
To implement an approximation algorithm for the Vertex Cover problem in C using an adjacency matrix representation of a graph.

Program:
#include <stdio.h>

#define V 5   // Number of vertices

// Function to find an approximate vertex cover
void findVertexCover(int graph[V][V]) 
{ 
    int visited[V]; 

    // Initialize all vertices as not selected
    for (int i = 0; i < V; i++) 
    { 
        visited[i] = 0; 
    } 

    // Traverse all edges in the graph
    for (int u = 0; u < V; u++) 
    { 
        for (int v = u + 1; v < V; v++)   // avoid duplicate checking
        { 
            // If an edge exists between u and v
            if (graph[u][v] == 1) 
            { 
                // Mark both endpoints as part of vertex cover
                visited[u] = 1; 
                visited[v] = 1; 
            } 
        } 
    } 

    // Print result
    printf("Approximate Vertex Cover: "); 

    int count = 0; 

    for (int i = 0; i < V; i++) 
    { 
        if (visited[i]) 
        { 
            printf("%d ", i); 
            count++; 
        } 
    } 

    printf("\nTotal vertices in the cover: %d\n", count);
} 

int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 1, 0, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {0, 1, 0, 1, 1}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n"); 

    // Call function
    findVertexCover(graph); 

    return 0; 
}

Output:
Executing Vertex Cover Approximation...
Approximate Vertex Cover: 0 1 2 3 4 
Total vertices in the cover: 5
