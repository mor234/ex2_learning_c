
#include <stdio.h>
#include "myBank.h"
/*
This program Manages 50 bank accounts.
Practice in c in using arrays, loops etc.
*/
int main() {
	char option;
	double doubleNumber = 0;
	int accountNumber = 0;
	do {
		printf("\nPlease choose a transaction type:\n");
		printf(" O-Open Account\n");
		printf(" B-Balance Inquiry\n");
		printf(" D-Deposit\n");
		printf(" W-Withdrawal\n");
		printf(" C-Close Account\n");
		printf(" I-Interest\n");
		printf(" P-Print\n");
		printf(" E-Exit\n");  
		int flag=scanf("\n%c", &option);
		while (flag== 0 ||option == ' ')
		{
			flag=scanf("\n%c", &option);
		} //if didn't read or if read ' ', read again
	
		switch (option) {
		case 'O':
			printf("Please enter amount for deposit: ");
			if (scanf("%lf", &doubleNumber) != 1) {
				printf("Failed to read the amount\n");
			}
			else {
				accountNumber = openAccount(doubleNumber);
				switch (accountNumber) {
				case -2:
					printf("There aren't any avaliable account's: %d\n", accountNumber);
					break;
				case -1:
					printf("Invalid Amount\n");
					break;
				default: //accountNumber>-1,  there wasn't any error
					printf("New account number is: %d \n", accountNumber);
				}
			}
			break;
		case 'B':
			printf("Please enter account number: ");
			if (scanf("%d", &accountNumber) != 1) {
				printf("Failed to read the account number\n");
			}
			else if (!realAccountNumber(accountNumber)) {
				printf("Invalid account number\n");
			}
			else if (!isOpen(accountNumber)) {
				printf("This account is closed\n");
			}
			else {
				printf("The balance of account number %d is: %.2lf\n", accountNumber, balance(accountNumber));
			}
			break;


		case 'D':
			printf("Please enter account number: ");
			if (scanf("%d", &accountNumber) != 1) {
				printf("Failed to read the account number\n");
			}
			else if (!realAccountNumber(accountNumber)) {
				printf("Invalid account number\n");
			}
			else if (!isOpen(accountNumber)) {
				printf("This account is closed\n");
			}
			else {
				printf("Please enter amount for deposit: ");
				if (scanf("%lf", &doubleNumber) != 1) {
					printf("Failed to read the amount\n");
				}
				else {
					doubleNumber = deposite(accountNumber, doubleNumber);

					if (doubleNumber == -1)
						printf("Cannot deposit a negative amount\n");
					else if (doubleNumber == -2)
						printf("Cannot withdraw more than the balance\n");
					else
						printf("The new balance is: %.2lf\n", doubleNumber);
				}
			}

			break;

		case 'W':
			printf("Please enter account number: ");
			if (scanf("%d", &accountNumber) != 1) {
				printf("Failed to read the account number\n");
			}
			else if (!realAccountNumber(accountNumber)) {
				printf("Invalid account number\n");
			}
			else if (!isOpen(accountNumber)) {
				printf("This account is closed\n");
			}
			else {
				printf("Please enter the amount to withdraw: ");
				if (scanf("%lf", &doubleNumber) != 1) {
					printf("Failed to read the amount\n");
				}
				else {
					doubleNumber = withdraw(accountNumber, doubleNumber);
					if(doubleNumber == -1)
						printf("Cannot withdraw more than the balance\n");
                    else
                    printf("The new balance is: %.2lf\n",doubleNumber);
				}
			}
			break;




		case 'C':
			printf("Please enter account number: ");
			if (scanf("%d", &accountNumber) != 1) {
				printf("Failed to read the account number\n");
			}
			else if (!realAccountNumber(accountNumber)) {
				printf("Invalid account number\n");
			}

			else if (!isOpen(accountNumber)) {
				printf("This account is already closed\n");
			}
			else {
				close(accountNumber);
				printf("Closed account number %d\n", accountNumber);
			}
			break;




		case 'I':
			printf("Please enter interest rate: ");
			int interst;
			if (scanf("%d", &interst) != 1) //I changed to int so the output will be as demanded
			{
				printf("Failed to read the interest rate\n");
			}
			else {
				if (addIntrest(interst) == -1)
					printf("Invalid interest rate\n");
			}
			break;


		case 'P':
			printAll();
			break;


		case 'E':
			closeAll();
			break;



		default:
			printf("Invalid transaction type\n"); //if got char who isn't in the options
			break;
		}
	}

	while (option != 'E');


	return 0;
}