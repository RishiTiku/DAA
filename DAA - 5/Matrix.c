#include <limits.h>
#include <stdio.h>
 
int A[100][2];

int Input()
{
    int n;
    printf("Enter number of Matrices.\n");
    scanf("%d", &n);

    printf("Matrix %d: m*n \n", 1);
    printf("Enter m.\n");
    scanf("%d", &A[0][0]);
    printf("Enter n.\n");
    scanf("%d", &A[0][1]);

    for(int i = 1; i<n; i++)
    {
        printf("Matrix %d: %d*n \n", i+1, A[i-1][1]);
        A[i][0] = A[i-1][1];
        printf("Enter n.\n");
        scanf("%d", &A[i][1]);
    }

    return n;
}

void Display(int size, int m[][size])//Accepts a sq matrix
{
    for(int i = 1; i<size; i++)
    {
        for(int j = 1; j<size; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }
    
}

void printParenthesis(int i, int j, int n, int* bracket, char * name)
{
    // If only one matrix left in current segment
    if (i == j) {
        printf("%c",(*name));
        (*name)++;
        return;
    }
 
    printf("(");
 
    // Recursively put brackets around subexpression from i to bracket[i][j].
    // "*((bracket+i*n)+j)" is similar to bracket[i][j]
    
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
 
    // Recursively put brackets around subexpression from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}

int MatrixChainOrder(int p[], int n)
{

    int m[n][n];
    int brac[n][n];
 
    int i, j, k, L, q;
    // i, j, k = loop, L = length of chain in loop, q used for min cost calculation
   
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            m[i][j] = 0;
            brac[i][j] = 0;
        }
    }
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    brac[i][j] = k;
                }
            }
        }
    }
    Display(n, m);
    printf("\n\n");
    Display(n, brac);

    for(i = n-1; i>2; i--)
    {
        int a = brac[1][i];

    }
    char name = 'A';
    printParenthesis(1, n - 1, n, (int*)brac, &name);
    printf("\n");

    return m[1][n - 1];
}
 
// Driver  code
int main()
{
    int N = Input();

    int D[N+1];

    D[0] = A[0][0];

    for(int k = 1; k<N; k++)
    {
        D[k] = A[k][0]; 
    }

    D[N] = A[N-1][1];

    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(D, N+1));
 
    getchar();
    return 0;
}

//4 3 2 4 2 5