
#ifndef MYBANK_HEADER
#define MYBANK_HEADER 


/*open an account with intial deposite, print the new account number. 
openning an account is ossibale only if there re less then 50 aount return 0 if sucside, -1 if not*/
void openAccount (double initialDeposit);
/*return the balance, only allowed if the account is open*/
void balance (int accountNumber);
/*deposite, print the new balance,  only allowed if the account is open*/
void deposite (int accountNumber,double sumToDeposit );
/*withdraw, print the new balance,  
only allowed if there account is open and there is enough money*/
void withdraw (int accountNumber,double sumToWithdraw);
/*close an acountt only allowed if open*/
void close (int accountNumber);
/*add intrest in te given present to all the open accounts*/
void addIntrest( double intrestPresent );
/*print all the open accounts and their balance */
void printAll();
/*close all the accounts */
void closeAll();

#endif