#include "ATM.h"

int main() {
	system("color E0");

	printf("**********************************************************************\n");
	printf("*********Welcome to use Waterloo Bank Automatic Teller System*********\n");
	printf("**********************************************************************\n");
	printf("\t-------------------------------------------------\n");
	printf("\t|\t1.\tStart a new account\t\t|\n");
	printf("\t-------------------------------------------------\n");
	printf("\t|\t2.\tLogin\t\t\t\t|\n");
	printf("\t-------------------------------------------------\n");
	printf("\t|\t3.\tInformation Center\t\t|\n");
	printf("\t-------------------------------------------------\n");
	printf("\t|\t4.\tPlease Choose Your Needs\t|\n");
	printf("\t-------------------------------------------------\n");

	char ch = getch();

	switch (ch) {
	case '1':
		CreateAccount();
		break;
	case '2':
		Login();
		break;
	case '3':
		break;
	case '4':
		break;
	default:
		break;
	}

	return 0;
}