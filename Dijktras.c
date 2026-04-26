Aim:
To implement Dijkstra’s Algorithm in C to find the shortest path from a source vertex (vertex 0) to all other vertices in a weighted graph using an adjacency matrix.

Program:
#include <stdio.h>

#define V 5       // Number of vertices in the graph
#define INF 999999 // Represents infinity (no direct connection)

// Function to find the vertex with minimum distance value
int extractMin(int dist[], int visited[]) 
{ 
    int min = INF, min_index = -1;

    // Loop through all vertices
    for (int v = 0; v < V; v++) 
    { 
        // Select the unvisited vertex with smallest distance
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v]; 
            min_index = v; 
        } 
    } 
    return min_index; 
} 

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V]) 
{ 
    int dist[V], visited[V]; 

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++) 
    { 
        dist[i] = INF; 
        visited[i] = 0;
    } 

    dist[0] = 0; // Distance from source (vertex 0) to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V; count++) 
    { 
        int u = extractMin(dist, visited); // Pick minimum distance vertex

        if (u == -1) 
            break; // No reachable vertex left

        visited[u] = 1; // Mark vertex as visited

        // Update distance value of adjacent vertices
        for (int j = 0; j < V; j++) 
        { 
            // Check if there is an edge and vertex is not visited
            if (graph[u][j] > 0 && !visited[j]) 
            { 
                // Update distance if shorter path is found
                if (dist[j] > dist[u] + graph[u][j]) 
                {
                    dist[j] = dist[u] + graph[u][j]; 
                } 
            }
        } 
    } 

    // Print shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d --> %d\n", i, dist[i]); 
} 

// Main function
int main() 
{ 
    // Adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 10, 0, 30, 100}, 
        {10, 0, 50, 0, 0}, 
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60}, 
        {100, 0, 10, 60, 0}
    }; 

    // Call Dijkstra function
    dijkstra(graph); 

    return 0; 
}

Output:

Vertex 	 Distance from Source (0)
0 --> 0
1 --> 10
2 --> 50
3 --> 30
4 --> 60
