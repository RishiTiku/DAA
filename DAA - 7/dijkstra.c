#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minDistance(int V, int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int ver = 0; ver < V; ver++)
    {
		if (sptSet[ver] == false && dist[ver] <= min)
        {
			min = dist[ver];
            min_index = ver;
        }
    }
	return min_index;
}

void printSolution(int V, int dist[])
{
	printf("\n\nVertex \t\t Distance from Source\n");
    //printf("-----------------------------------------\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t %d\n", i, dist[i]);
}

void dijkstra(int V, int weight[V][V], int src)
{
	int dist[V]; 
	bool sptSet[V];
	for (int i = 0; i < V; i++)
    {
		dist[i] = INT_MAX, sptSet[i] = false;
    }

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(V, dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
        {
			if (!sptSet[v] && weight[u][v] && dist[u] != INT_MAX && dist[u] + weight[u][v] < dist[v])
			{
                dist[v] = dist[u] + weight[u][v];
            }
        }
	}

	printSolution(V, dist);
}

int main()
{
	int s, e, w, v, ch;

    printf("Enter no. of vertices: ");
    scanf("%d", &v);
    
    int weight[v][v];

    printf("\nEnter edges and their weights:-");
    do{
        printf("\nStart Point: ");
        scanf("%d",&s);
        printf("End Point: ");
        scanf("%d",&e);
        printf("Weight: ");
        scanf("%d",&w);
        weight[s][e] = w;
        weight[e][s] = w;
        printf("\nEnter 0 to stop: ");
        scanf("%d",&ch);
    }while(ch!= 0);

	dijkstra(v, weight, 0);
    return 0;
}
