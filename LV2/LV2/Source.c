#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);



struct NODE {
	float data;
	struct NODE* next;
};
typedef struct NODE node;

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
		if (V[i] == x) {
			return i;
		}

	}
	return -1;
}


int sekv_pret_ll(node* prvi, float x)
{
	node* current = prvi;
	while (current != NULL)
	{
		
		if (current->data == x)
			return 1;
		current = current->next;
		
	}
	return 0;
}



int main(void)
{	
	int n = 0;
	float* arr;

    printf("Unesite broj elemenata:");
	scanf("%d", &n);

	arr = (float*)malloc(n * sizeof(float));

	time_t vrijeme1, vrijeme2;


	vrijeme1 = clock();
	gen_arr(arr, n, 0, 10000);
	vrijeme2 = clock();
	printf("Vrijeme za stvaranje arraya : %dms\n", vrijeme2 - vrijeme1);

	vrijeme1 = clock();
	sekv_pret(arr, n, 101.3123231);
	vrijeme2 = clock();
	printf("Vrijeme za sequential search : %dms\n", vrijeme2 - vrijeme1);

	
	vrijeme1 = clock();
	node* prvi = NULL;
	node* current = NULL;
	for (int k = 0; k < n; k++) {
		if (k == 0) {
			prvi = (node*)malloc(sizeof(node));
			current = prvi;
		}
		else {
			current->next = (node*)malloc(sizeof(node));
			current = current->next;

		}

		//for (int i = 1;i < n;i++)
		//{
			//clan->data = V[i];
		//}
		current->data = 0 + (float)rand() / RAND_MAX * (1000000 - 0 + 1);

	}
	current->next = NULL;
	vrijeme2 = clock();
	printf("Vrijeme za kreairanje povezanog popisa : %dms\n", vrijeme2 - vrijeme1);

	vrijeme1 = clock();
	sekv_pret_ll(prvi, 101.21421412);
	vrijeme2 = clock();
	printf("Vrijeme za pretrazivanje povezanog popisa : %dms\n", vrijeme2 - vrijeme1);

	return 0;
}
