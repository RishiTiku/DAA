#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Display(int N, int A[N][N])
{
    printf("\n     ");
    for(int i = 0; i<N; i++)
    {
        printf("%d    ", i);
    }
    printf("\n   ");
    for(int i = 0; i<N; i++)
    {
        printf("-----");
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < N; j++)
        {
            printf(" %d | ", A[i][j]);

        }
        printf("\n   ");
       for(int k = 0; k<N; k++)
        {
            printf("-----");
        }
        printf("\n");
    }
}

bool isSafe(int N, int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive function to solve N
Queen problem using DFS*/
bool DFS(int N, int board[N][N], int depth)
{
	/* base case: If all queens are placed
	then print */
	if (depth >= N)
	{   
        char ch;
        //printSolution(N, board);
        printf("\nSolution: \n");
        Display(N, board);
        printf("\nPress Enter Key for Next solution.");
        fflush(stdin);
        scanf("%c", &ch);
        printf("\n");
        return false;
    }

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on
		board[i][depth] */
		if (isSafe(N, board, i, depth)) {
			{/* Place this queen in board[i][depth] */
                char ch;
                board[i][depth] = 1;
            }
            DFS(N, board, depth + 1);

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][depth] */
			board[i][depth] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in
		this column col then return false */
	return false;
}

bool solveNQ(int N)
{
	int board[N][N];

    for(int i = 0 ; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            board[i][j] = 0;
        }
    }

	if (N == 2 || N == 3) {
		printf("Solution does not exist");
		return false;
	}
    DFS(N,board, 0);
	return true;
}

// main function
int main()
{
    int N = 0;
    printf("Input N: \n");
    scanf("%d", &N);
	solveNQ(N);
	return 0;
}
