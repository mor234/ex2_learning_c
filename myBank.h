
#ifndef MYBANK_HEADER
#define MYBANK_HEADER 

#include <stdbool.h>



//checks if the account number is in the range of valid accounts numbers
bool realAccountNumber(int accountNumber);
//checks if the account is open,
//assumes the account number is in range
bool isOpen(int accountNumber);
/*
Method that open an account with intial deposite,
return the new account number.
openning an account is possibale only if:
- there are less then 50 accounts; 
- the deposite is positive;
*/
int openAccount(double initialDeposit);
/*
Method that returns the balance of a given account, assumes:
- the given accountNumber is in range,
- the account is open
*/
double balance(int accountNumber);
/*
Method that deposite a positive sum into a givan account, assumes:
- the given accountNumber is in range
- the account is open
 if the sumToDeposit <0 : return -1, sign for error
 */
double deposite(int accountNumber, double sumToDeposit);
/*
This metode withdraw from a given account,
and return the new balance. assumes:
- the given accountNumber is in range
- the account is open
 not allowed to withdraw more then the sum in the account.
 return -1 if such attempt is made
*/
double withdraw(int accountNumber, double sumToWithdraw);
/*
close an account , assume:
- the given accountNumber is in range,
- the account is open
*/
void close(int accountNumber);
/*
add intrest in the given present to all the open accounts
the intrest need to be positive. if not, return -1
*/
int addIntrest(double intrestPresent);
/*print all the open accounts and their balance */
void printAll();
/*close all the accounts */
void closeAll();


#endif