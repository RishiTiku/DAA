#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minKey(int V, int key[], bool used[])
{
	int min = INT_MAX, min_index;

	for (int ver = 0; ver < V; ver++)
    {
		if (used[ver] == false && key[ver] < min)
		{
            min = key[ver];
            min_index = ver;
        }
    }
	return min_index;
}

int printMST(int V, int parent[], int weight[V][V])
{
    int cost = 0;
	printf("\nEdge \t|\tWeight\n----------------------\n");
	for (int i = 1; i < V; i++)
    {
		printf("%d - %d \t|\t%d \n", parent[i], i, weight[parent[i]][i]);
        cost += weight[parent[i]][i];
    }
    printf("\nTotal cost = %d\n", cost);
}

void primMST(int V, int weight[V][V])
{
	int parent[V];
	int key[V];
	bool used[V];

	for (int i = 0; i < V; i++)
    {
		key[i] = INT_MAX, used[i] = false;
    }

	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
    {
		int u = minKey(V, key, used);
		used[u] = true;

		for (int v = 0; v < V; v++)
        {
			if (weight[u][v] && used[v] == false && weight[u][v] < key[v])
            {
				parent[v] = u;
                key[v] = weight[u][v];
            }
        }
	}

	printMST(V, parent, weight);
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

	primMST(v, weight);

	return 0;
}

//5 0 1 2 1 0 3 6 1 1 2 3 1 1 3 8 1 1 4 5 1 2 4 7 1 3 4 9 0