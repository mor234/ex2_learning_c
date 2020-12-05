
#include <stdio.h>
#include "myBank.h"
#define firstAccount 901
#define lastAccount 950
#define numberOfAccounts 50

double accounts[2][numberOfAccounts];
int numberOfOpenAccounts = 0;

/*
Method that checks if the account number is
in the range of valid account numbers
return true if i range, false if not
*/
bool realAccountNumber(int accountNumber) {
	return (accountNumber <= lastAccount && accountNumber >= firstAccount);
}
/*
Method that checks if the account  is open
return true if open, false if not 
*/
bool isOpen(int accountNumber) {
	return accounts[1][accountNumber - firstAccount];
}


/*
Method that open an account with intial deposite,
print the new account number.
openning an account is possibale only if there are less then 50 accounts
*/
int openAccount(double initialDeposit) {
	if (numberOfOpenAccounts == numberOfAccounts) {
		return -2; //Error. no avalable accounts
	}
	if (initialDeposit < 0) {
		return -1; //Error. Invalid Amount
	}
	for (int i = 0; i < numberOfAccounts; i++) {
		if (accounts[1][i] == 0) //if not open
		{
			numberOfOpenAccounts++;
			accounts[1][i] = 1; //sign it's open
			accounts[0][i] = initialDeposit;
			return firstAccount + i; //finish
		}
	}
    return -2;
}
/*
return the balance, only allowed if the account is open
*/
double balance(int accountNumber) {
	//print balance
	return accounts[0][accountNumber - firstAccount];
	//
}
/*
deposite, print the new balance,  only allowed if the account is open*/
double deposite(int accountNumber, double sumToDeposit) {
	if (sumToDeposit < 0) {
		return -1; //Error. Cannot deposit a negative amount
	}
	//deposite
	accounts[0][accountNumber - firstAccount] += sumToDeposit;
	return accounts[0][accountNumber - firstAccount];
}
/*
This metode withdraw from a given account,
and return the new balance.
if sumToWithdraw < 0 or the sumToWithdraw if bigger then balance
don't withdraw, and return -1, -2 ; sign for Error
*/
double withdraw(int accountNumber, double sumToWithdraw) {
	// if (sumToWithdraw < 0) {
	// 	return -1; //Error. Cannot Withdraw a negative amount
	// }
	
	if (accounts[0][accountNumber - firstAccount] >= sumToWithdraw) {
		//withdraw
		accounts[0][accountNumber - firstAccount] -= sumToWithdraw;
		return accounts[0][accountNumber - firstAccount];
	}
	else
		return -2; //Error. Cannot withdraw more than the balance
}
/*
close an account , assume:
- the given accountNumber is in range,
- the account is open
*/
void close(int accountNumber) {

	numberOfOpenAccounts--;
	accounts[1][accountNumber - firstAccount] = 0; //sign it's closed
}
/*add intrest in the given present to all the open accounts*/
int addIntrest(double intrestPresent) {
	if (intrestPresent <= 0) {
		return -1; //Error. Invalid interest rate
	}
	for (int i = 0; i < numberOfAccounts; i++) {
		if (accounts[1][i] == 1) //if  open
		{
			accounts[0][i] += accounts[0][i] * (intrestPresent / 100);
		}
	}
	return 0;
}
/*print all the open accounts and their balance */
void printAll() {
	for (int i = 0; i < numberOfAccounts; i++) {
		if (accounts[1][i] == 1) //if open
		{
			printf("The balance of account number %d is: %.2lf\n", i + firstAccount, accounts[0][i]);
		}
	}
}
/*close all the accounts */
void closeAll() {
	for (int i = 0; i < numberOfAccounts; i++) {
		accounts[1][i] = 0; //close
	}
	numberOfOpenAccounts = 0;
}