#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

struct NODE {
	int data;
	struct NODE* next;
};
typedef struct NODE node;


int main(void)
{
	int n = 0;

	printf("Unesite broj elemenata:");
	scanf("%d", &n);

	
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

		current->data = 0 + (float)rand() / RAND_MAX * (1000000 - 0 + 1);

	}
	current->next = NULL;
	

	return 0;
}

//Sekvencijalno pretraživanje - O(n)
int sekv_pret_ll(node* prvi, float x)
{
	node* current = prvi;
	while (current != NULL)
	{

		if (current->data == x)
			return 1; // Ukoliko se trazi ispis od npr. DA ako je element pronađen
		//to se radi umjesto ovim return funkcija,znaci samo ubaciti printf("DA"); ili 
		//tako nesto
		current = current->next;

	}
	return 0;
}

//Brisanje elementa lise na poziciji -position
void deleteNodeByPosition(node** prvi, int position)
{
	if (*prvi == NULL)
		return;

	node* temp = *prvi;

	if (position == 0) { //Provjera jel zelim obrisati head node

		*prvi = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; temp != NULL && i < position - 1;i++) { //For do positiona gjde zelim obrisati
		//+ provjera jel uopce postoji ta vrijednost na toj poziciji
		temp = temp->next;
	}

	if (temp = NULL || temp->next == NULL) {
		return;
	}

	node* next = temp->next->next;

	free(temp->next);

	temp->next = next;
}

//Brisanje element sa vrijednosti -value
void deleteNodeByValue(node** prvi, int value)
{
	node* temp = *prvi;
	node* current = *prvi;

	if (temp != NULL && temp->data == value) {
		*prvi = temp->next; 
		free(temp); 
		return;
	}

	while (temp != NULL && temp->data != value) {
		current = temp;
		temp = temp->next;
	}


	if (temp == NULL)
		return;

	current->next = temp->next;

	free(temp); 
}
//Obrisi sve elemente liste
void deleteList(node** prvi) {
	node* current = *prvi;
	node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*prvi = NULL;

}
//Ubacivanje elementa na kraj liste
void insertatEnd(node** prvi, int value) {

	//stvori novi node
	node* temp = malloc(sizeof(node));
	temp->data = value;
	temp->next == NULL;

	if (*prvi == NULL) {  //Provjera jel lista prazna
		*prvi = temp;
	}
	else {
		node* last = *prvi;

		while (last->next != NULL) {
			last = last->next;
		}
		last->next = temp;
	}
}

//Ubacivanje elementa na pocetak liste
void insertatStart(node** prvi, int value) {
	node* temp = (node*)malloc(sizeof(node));

	temp->data = value;
	temp->next = *prvi;
	*prvi = temp;


}


//Ispisi sredinu
void printMiddle(node* head)
{
	node* slow_ptr = head;
	node* fast_ptr = head;

	if (head != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		printf("The middle element is [%d]\n\n", slow_ptr->data);
	}
}


void addInMid(node** prvi,int data) {
	int i;
	int size = 0;
	node* temp = (node*)malloc(sizeof( node));
	node* tail;
	temp->data = data; 
	if (prvi== NULL) { 
		prvi = temp;
		tail = temp;
		temp->next = prvi;
	}
	else {
		struct node* temp, * current = NULL;  
		int count = (size % 2 == 0) ? (size / 2) : ((size + 1) / 2);
		temp = prvi;
		for (i = 0; i < count; i++) {
			current = temp; 
			temp = temp->next;
		}
		current->next = temp;
		temp->next = temp;
	}
	size++;
}