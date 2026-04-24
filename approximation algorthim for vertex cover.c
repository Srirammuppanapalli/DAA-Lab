#include <stdio.h> 
	#define V 5
	
	void findVertexCover(int graph[V][V]) 
    { 
	int visited[V]; 
	for (int i = 0; i < V; i++) 
	{ 
	visited[i] = 0; 
	} 
 
	for (int u = 0; u < V; u++) 
	{ 
	for (int v = 0; v < V; v++) 
	{ 
  
	
	{ 
	
	visited[u] = 1; 
		visited[v] = 1;   
                 
	} 
	}
	} 
	
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
	
	int graph[V][V] = { 
	{0, 1, 0, 0, 0}, 
	{1, 0, 1, 1, 0},
	{0, 1, 0, 1, 1}, 
    {0, 1, 1, 0, 1}, 
    {0, 0, 1, 1, 0}};
           
	printf("Executing Vertex Cover Approximation...\n"); 
	findVertexCover(graph); 
    return 0; 
    }

Output:
Executing Vertex Cover Approximation...
Approximate Vertex Cover: 0 1 2 3 4 
Total vertices in the cover: 5
