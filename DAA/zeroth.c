#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//helper functions
double fact(double n)//returns factorial
{
	double mult = 1;
	for(;n>=1;n--)
	{
		mult*=n;
	}
	return mult;
}

//actual functions
double fn1(double n)// (3/2)^n
{
    double a = pow((double)3/2, n);
	return a;
}

double fn2(double n)// n^3
{
	return pow(n, 3);
}

double fn3(double n)//log^2 n (base 2)
{
	return pow(log2(n), 2);
}

double fn4(double n)//log n! (base 2)
{
	return log2(fact(n));
}

double fn5(double n)//2^(2^n)
{
	return pow(2, pow(2, n));
}

double fn6(double n)//n ^ (1/log n) (base 2)
{
	return pow(n, (1/log2(n)));
}

double fn7(double n)//ln (ln n)
{
	return log(log(n));
}

double fn8(double n)//log n (base 2)
{
	return log2(n);	
}

double fn9(double n)//n . 2^n
{
	return n * pow(2, n);
}

double fn10(double n)//n^(log log n) (base 2)
{
	return pow(n, log2(log2(n)));
}

void table(double (*f)(double) )
{	
    //printf("%p\n", f);
	for ( int ctr = 0 ; ctr <=100 ; ctr+=10 )
	{
        double n = (*f)(ctr);
        printf("|\t%d\t|\t%lf\n",ctr, n);
	}
	printf("\n");
}


void main()
{
    
    printf("Function : 1 : (3/2)^n\n");
	table(fn1);
    printf("Function : 2 : n^3\n");
    table(fn2);
    printf("Function : 3 : log^2 n (base 2)\n");
    table(fn3);
    printf("Function : 4 : log n! (base 2)\n");
    table(fn4);
    printf("Function : 5 : 2^(2^n)\n");
    table(fn5);
    printf("Function : 6 : n ^ (1/log n) (base 2)\n");
    table(fn6);
    printf("Function : 7 : ln (ln n)\n");
    table(fn7);
    printf("Function : 8 : log n (base 2)\n");
    table(fn8);
    printf("Function : 9 : n . 2^n\n");
    table(fn9);
    printf("Function : 10 : n^(log log n) (base 2)\n");
    table(fn10);
    printf("Function : 11 : n!\n");
    for ( int ctr = 0 ; ctr <=20 ; ctr+=2 )
	{
        double n = fact(ctr);
        printf("|\t%d\t|\t%lf\n",ctr, n);
	}
	printf("\n");
}