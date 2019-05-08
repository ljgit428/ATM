#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _Account{
	char username[20];
	char pin[5];
	char accountnum[17];
	float money;
}Account;

typedef struct _Node{
	Account a;
	struct _Node* next;
}Node;

int CreateAccount();

int Login();

void Menu();
