
#ifndef MYBANK_HEADER
#define MYBANK_HEADER 

#include <stdbool.h>

/*open an account with intial deposite, print the new account number.
openning an account is ossibale only if there re less then 50 aount return 0 if sucside, -1 if not*/
int openAccount(double initialDeposit);
/*return the balance, only allowed if the account is open*/
double balance(int accountNumber);
/*deposite, print the new balance,  only allowed if the account is open*/
double deposite(int accountNumber, double sumToDeposit);
/*withdraw, print the new balance,
only allowed if there account is open and there is enough money*/
double withdraw(int accountNumber, double sumToWithdraw);
/*close an acountt only allowed if open*/
void close(int accountNumber);
/*add intrest in te given present to all the open accounts*/
int addIntrest(double intrestPresent);
/*print all the open accounts and their balance */
void printAll();
/*close all the accounts */
void closeAll();

//check if an account of this number is open.
bool isOpen(int accountNumber);

//checks if the account number is in the range of valid account numbers
bool realAccountNumber(int accountNumber);


#endif