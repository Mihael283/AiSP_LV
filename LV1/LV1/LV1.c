#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gen_arr( float V[], int n, float dg, float gg );
int sekv_pret( float V[], int n, float x );
void swap(float *a, float* b);
void heapify(float V[], int n, int i);
void sort( float V[], int n );
int bin_pret( float V[], int n, float x );

void gen_arr(float V[], int n, float dg, float gg)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg + 1);
	}

}


int sekv_pret(float V[], int n, float x)
{

	for (int i = 0; i < n; i++)
	{
		if (V[i]== x) {
			return i;
		}
		
	}
	return -1;
}

void swap(float *a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(float V[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2; 

	if (l < n && V[l] > V[largest])
		largest = l;

	if (r < n && V[r] > V[largest])
		largest = r;

	if (largest != i) {
		swap(&V[i], &V[largest]);


		heapify(V, n, largest);
	}
}

void sort(float V[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(V, n, i);

	for (int i = n - 1; i > 0; i--) {
		
		swap(&V[0], &V[i]);

		
		heapify(V, i, 0);
	}
}


int bin_pret(float V[], int n, float x)
{
	int dg=0;
	int gg=n-1;
	int s=-1;

	while(dg<=gg){
		s=(dg+gg)/2;
		
		if(V[s] == x){
			return s;
		}
		else if (V[s]>x){
			gg=s-1;
		}
		else{
			dg=s+1;
		}
	}

	return -1;
}

int main(void)
{	//Sekv O(n)
	//Heap sort O(n log n)
	//Bin O(log n)
	int n = 10000000;
	float* arr;

	arr = (float*)malloc(n * sizeof(float));

	time_t vrijeme1, vrijeme2;

	gen_arr(arr, n, 0, 10000);

	vrijeme1 = clock();
	sekv_pret(arr, n, 101.3123231);
	vrijeme2 = clock();
	printf("Vrijeme za sequential search : %dms\n", vrijeme2 - vrijeme1);

	vrijeme1 = clock();
	sort(arr, n);
	vrijeme2 = clock();
	printf("Vrijeme za heap sort : %dms\n", vrijeme2 - vrijeme1);

	vrijeme1 = clock();
	bin_pret(arr, n, 101.3123231);
	vrijeme2 = clock();
	printf("Vrijeme za binary search : %dms\n", vrijeme2 - vrijeme1);

	return 0;
}

