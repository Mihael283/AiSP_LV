#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int x1 = 0;
int x2 = 0;
int stog1[N];
int stog2[N];
int stackpush1 = 0;
int stackpush2 = 0;

int povrh(int n, int m)
{
    if (m > n)
        return 0;
    if (m == 0 || m == n)
        return 1;

    return povrh(n - 1, m - 1) + povrh(n - 1, m);
       
}

void push_stog1(int x)
{
	if (stackpush1 == N)
	{
		printf("Stack overflow!");
	}
	else
	{
		stackpush1 = stackpush1 + 1;
		stog1[stackpush1] = x;
	}
}

void push_stog2(int x)
{
	if (stackpush2 == N)
	{
		printf("Stack overflow!");
	}
	else
	{
		stackpush2 = stackpush2 + 1;
		stog2[stackpush2] = x;
	}
}

int pop1() {
	if (stackpush1 == 0) {
		printf("Stack Underflow!");
	}
	else
	{
		x1 = stog1[stackpush1];
		stackpush1 = stackpush1 - 1;
		return x1;
	}
}

int pop2() {
	if (stackpush2 == 0) {
		printf("Stack Underflow!");
	}
	else
	{
		x2 = stog2[stackpush2];
		stackpush2 = stackpush2 - 1;
		return x2;
	}
}

void povrhS(int a, int b)
{
	push_stog1(a);
	push_stog2(b);
	int povrh = 0;

	while (stackpush1 != 0)
	{
		a = pop1();
		b = pop2();

		if (a == b || b == 0)
		{
			povrh = povrh + 1;
		}
		else
		{
			push_stog1(a - 1);
			push_stog2(b - 1);
			push_stog1(a - 1);
			push_stog2(b);
		}
	}
	printf("%d", povrh);
}

int main()
{   
    time_t vrijeme1, vrijeme2, vrijeme3, vrijeme4;
    int n = 20, m = n/2;

    vrijeme1 = clock();
    printf("Rezultat od C(%d, %d) je %d ", n, m, povrh(n, m));    
    vrijeme2 = clock();
    printf("Vrijeme za standardnu rekurziju : %dms\n", vrijeme2 - vrijeme1);


	vrijeme3 = clock();
	printf("Rezultat od C(%d, %d) je ", n, m);
	povrhS(n, m);
	vrijeme4 = clock();
	printf(" Vrijeme za stog : %dms\n", vrijeme4 - vrijeme3);
	
    return 0;
}

