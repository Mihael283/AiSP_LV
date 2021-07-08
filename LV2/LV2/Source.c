#include<stdio.h>
#include<stdlib.h>
typedef struct CVOR {
	char c;
	struct CVOR* left;
	struct CVOR* right;
}cvor;
int nadji_p(char c);
void dodaj_p(char c);
void preOrder(cvor* korijen);
void inOrder(cvor* korijen);
void postOrder(cvor* korijen);
cvor* korijen = NULL, * nadred = NULL;
int main(void) {
	char polje[] = { 'M','I','H','A','E','L','S','P','A','N','O','V','I','C','\0' };
	for (int i = 0; polje[i] != '\0'; i++) {
		dodaj_p(polje[i]);
	}
	preOrder(korijen);
	putchar(' ');
	inOrder(korijen);
	putchar(' ');
	postOrder(korijen);
	putchar(' ');
}

int nadji_p(char c) {
	int br = 0;
	cvor* cvor_t = korijen;
	nadred = NULL;
	if (cvor_t == NULL) {
		return -1;
	}
	while (1) {
		if (cvor_t->c == c) {
			br = 1;
		}
		else {
			nadred = cvor_t;
			if (cvor_t->c > c) {
				if (cvor_t->left != NULL)cvor_t = cvor_t->left;
				else br = -1;
			}
			else
				if (cvor_t->right != NULL)cvor_t = cvor_t->right;
				else br = -1;
		}
		if (br == 1 || br == -1)break;


	}
	return br;
}
void dodaj_p(char c) {
	cvor* novi;
	int br = 0;
	br = nadji_p(c);
	if (br == 1) {
		return;
	}
	else {
		novi = (cvor*)malloc(sizeof(cvor));
		novi->c = c;
		novi->left = novi->right = NULL;
		if (nadred == NULL) {
			korijen = novi;
		}
		else {
			if (nadred->c > novi->c)nadred->left = novi;
			else nadred->right = novi;
		}
	}
}
void preOrder(cvor* korijen) {

	if (korijen == NULL) {

		return;
	}
	else {

		printf("%c", korijen->c);
		preOrder(korijen->left);
		preOrder(korijen->right);
	}

}
void inOrder(cvor* korijen) {

	if (korijen == NULL) {

		return;
	}
	else {

		inOrder(korijen->left);
		printf("%c", korijen->c);
		inOrder(korijen->right);
	}

}
void postOrder(cvor* korijen) {

	if (korijen == NULL) {

		return;
	}
	else {

		postOrder(korijen->left);
		postOrder(korijen->right);
		printf("%c", korijen->c);
	}

}