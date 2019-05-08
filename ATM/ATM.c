#include "ATM.h"

extern Node *first = NULL;

int CreateAccount() {
	Node *newnode = malloc(sizeof(Node));
	newnode->next = NULL;

	printf("Please enter your name:\n");
	scanf("%s", newnode->a.username);
	newnode->a.money = 0;

	while (1) {

		char enterpin[5];
		printf("Please enter your PIN number:\n");
		scanf("%s", enterpin);
		printf("Please enter your PIN number again:\n");
		scanf("%s", newnode->a.pin);

		if (0 != strcmp(enterpin, newnode->a.pin)) {
			printf("You have entered different PIN numbers. Please enter your PIN numbers again\n");
			continue;
		}


		break;
	}
	srand((unsigned int)time(NULL));
	sprintf(newnode->a.accountnum, "%d%d%d%d",
		rand() % 9000 + 1000,
		rand() % 9000 + 1000,
		rand() % 9000 + 1000,
		rand() % 9000 + 1000);

	if (first) {
		first->next = first;
		first = newnode;
	}
	else {
		first = newnode;
	}

	printf("Your account information is:\n");
	printf("\tName: %s\n", newnode->a.username);
	printf("\tAccount Number: %s\n", newnode->a.accountnum);
	printf("\tBalance: %.2f\n", newnode->a.money);
	printf("\nCongratulations! Your account has been successfully created! Please log in\n");

	printf("%s\n", newnode->a.pin);

	system("pause");
	system("cls");
	Login();

	
	return 1;
}

int Login() {
	system("cls");
	printf("**********************************************************************\n");
	printf("*********Welcome to use Waterloo Bank Automatic Teller System*********\n");
	printf("**********************************************************************\n");

	char accountnum[17];
	char pin[5];

	printf("Please enter your account number:\n");
	scanf("%s", accountnum);

	Node *p = first;
	while (p != NULL) {
		if (strcmp(p->a.accountnum, accountnum) != 0) {
			p = p->next;
			continue;
		}
		else {
			int i;
			for (i = 1; i <= 3; i++) {
				printf("Please enter your PIN number:\n");
				scanf("%s", pin);
				if (strcmp(p->a.pin, pin) != 0) {
					printf("Wrong PIN numbers. Please enter your PIN numbers again. %d times left\n", 3 - i);
				} else {
					system("cls");
					Menu(p);
					return 1;
				}
			}

			if (i > 3) {
				printf("Your account is locked. Please try again after 2 hours.");
				return 0;
			}
		}
	}
	return 1;
}

void Menu(Node* pnode) {
	while (1) {
		printf("*************Please choose the service you require*************\n");
		printf("**** ① Deposit                  ② Withdraw               ****\n");
		printf("**** ③ Transfer                 ④ Change PIN             ****\n");
		printf("**** ⑤ Account Information      ⑥ Exit                   ****\n");
		printf("***************************************************************\n");


		char ch = getch();

		switch (ch) {
		case '1':
			pnode->a.money += 100;
			break;
			printf("Your account balance is: $%.2f\n", pnode->a.money);
		case '2':
			pnode->a.money -= 100;
			printf("Your account balance is: $%.2f\n", pnode->a.money);
			break;
		case '3':
			char accountnum[17];
			printf("Please enter the other account number you want to transfer to:\n");
			scanf("%s", accountnum);
			Node *p = first;
			while (p != NULL) {
				if (strcmp(p->a.accountnum, accountnum) != 0) {
					p = p->next;
					continue;
				}
				else {
					pnode->a.money -= 100;
					p->a.money += 100;
					printf("Your account balance is: $%.2f\n", pnode->a.money);
				}
			}
			break;
		case '4':
			printf("Please enter your new PIN number:\n");
			scanf("%s", pnode->a.pin);
			break;
		case '5':
			system("cls");
			printf("Your account balance is: $%.2f\n", pnode->a.money);
			break;
		case '6':
			return;
			break;
		default:
			break;
		}
	}
}