#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int * A, int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
}

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void SelectionSort(int * A, int n)
{
    for(int i = 0; i<n; i++)
    {
        int min = A[i];
        int pos = i;
        int temp;
        for(int j = i; j<n; j++)
        {
            if(A[j]<min)
            {
                min = A[j];
                pos = j;
            }
        }
        temp = A[i];
        A[i] = min;
        A[pos] = temp;
    }
}

int genFile()
{
    FILE * fptr;
    if(!(fptr = fopen("RandomNumbers.txt", "w")))
    {
        return 1;
    }

    for(int i = 0; i<100000; i++)
    {
        fprintf(fptr, "%d\n", rand());
    }

    fclose(fptr);
    return 0;
}


int main()
{
    genFile();
    FILE * fptrs, * fptrd;
    fptrd = fopen("times.csv", "w");
    if(!fptrd)
        return 0;
    fprintf(fptrd, "Cases, Selection, Insertion\n");
    
    for(long int x = 100; x<=100000; x+=100)
    {
        fptrs = fopen("RandomNumbers.txt", "r");
        int A[x], B[x];
        clock_t start1, end1, start2, end2;
        if(x % 1000 == 0)
        {
            printf("x = %ld.\n", x);
        }

        for(long int i = 0; i<x; i++)
        {
            fscanf(fptrs, "%d\n", &A[i]);
            B[i] = A[i];
        }

        start1 = clock();
        SelectionSort(A, x);
        end1 = clock();

        start2 = clock();
        InsertionSort(B, x);
        end2 = clock();

        double t1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        double t2 = (double) (end2 - start2) / CLOCKS_PER_SEC;

        fprintf(fptrd, "%ld, %f, %f\n", x, t1, t2);

        fclose(fptrs);
    }
    fclose(fptrd);
}