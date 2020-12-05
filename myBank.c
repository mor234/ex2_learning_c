
#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define firstAccount 901
#define lastAccount 950
#define numberOfAccounts 50

double accounts [2][numberOfAccounts];
int numberOfOpenAccounts=0;
/*Method that checks if the account number is 
in the range of valid account numbers
return true if i range, false if not*/
bool realAccountNumber (int accountNumber)
{
   return(accountNumber <= lastAccount&& accountNumber>=firstAccount);
}
/*Method that checks if the account  is open
return true if open, false if not */
bool isOpen(int accountNumber)
{
   return accounts[1][accountNumber-firstAccount];
}
/*
Method that handels the following errors:
- the given accountNumber is invalide
- the given account is closed
prints the error and return true if one of the error acuured,
 else return false*/

bool error_not_an_account_or_not_open(int accountNumber){
    if (!realAccountNumber(accountNumber))
    {
        printf("Invalid account number\n");
        return true;
    }
    if(!isOpen(accountNumber))
    {
        printf("This account is closed\n");
        return true;
    }
    return false;
}

/*Method that open an account with intial deposite,
 print the new account number. 
openning an account is possibale only if there are less then 50 accounts
*/
void openAccount (double initialDeposit)
{
    if (numberOfOpenAccounts==numberOfAccounts)   
    {
        return;
    }
    if (initialDeposit<0)
    {
        printf("Invalid Amount\n");
        return;    
    }
    for(int i=0;i<numberOfAccounts;i++)
    {
        if(accounts[1][i]==0)//if not open
        {
            numberOfOpenAccounts++;
            accounts[1][i]=1;//sign it's open
            accounts[0][i]=initialDeposit;
            printf("New account number is: %d\n",firstAccount+i); 
            return;//finish

        }
    }
    
}
/*return the balance, only allowed if the account is open*/
void balance (int accountNumber)
{
    if(error_not_an_account_or_not_open(accountNumber))
        return;
    
    
    //print balance
     printf("The balance of account number %d is: %.2lf\n",accountNumber, accounts[0][accountNumber-firstAccount]);
    


}
/*deposite, print the new balance,  only allowed if the account is open*/
void deposite (int accountNumber,double sumToDeposit )
{
    if(error_not_an_account_or_not_open(accountNumber))
        return;
    if (sumToDeposit<0)
    {
        //hendel error
        printf("Cannot deposit a negative amount\n");
        return;
    }
    //deposite
    accounts[0][accountNumber-firstAccount]+=sumToDeposit;

    printf("The new balance is: %.2lf\n", accounts[0][accountNumber-firstAccount]);

}
/*withdraw, print the new balance,  
only allowed if there account is open and there is enough money*/
void withdraw (int accountNumber,double sumToWithdraw)
{
    if(error_not_an_account_or_not_open(accountNumber))
        return;

     if (sumToWithdraw<0)
    {
        printf("Cannot Withdraw a negative amount\n");
        return;
    }

    if( accounts[0][accountNumber-firstAccount]>=sumToWithdraw)
    {
        //withdraw
        accounts[0][accountNumber-firstAccount]-=sumToWithdraw;
        printf ("The new balance is: %.2lf\n",accounts[0][accountNumber-firstAccount]);
    }


}
/*close an account ,only allowed if open*/
void close (int accountNumber)
{
     if (!realAccountNumber(accountNumber))
    {
        printf("Invalid account number\n");
        return;
    }
   
    if(!isOpen(accountNumber))
    {
        printf("This account is already closed\n");  
        return;
    }

    numberOfOpenAccounts--;
    accounts[1][accountNumber-firstAccount]=0;//sign it's closed
    printf("Closed account number %d\n",accountNumber); 
}
/*add intrest in the given present to all the open accounts*/
void addIntrest( double intrestPresent )
{
    if(intrestPresent<=0) {
    printf("Invalid interest rate\n");
    }
    for(int i=0;i<numberOfAccounts;i++)
    {
        if(accounts[1][i]==1)//if  open
        {
            accounts[0][i]*=intrestPresent;
        }
    }
}
/*print all the open accounts and their balance */
void printAll()
{
    for(int i=0;i<numberOfAccounts;i++)
    {
        if(accounts[1][i]==1)//if open
        {
            printf("The balance of account number %d is: %.2lf\n",i+firstAccount,accounts[0][i]);
        }
    }
}
/*close all the accounts */
void closeAll()
{
     for(int i=0;i<numberOfAccounts;i++)
    {
        accounts[1][i]=0;//close    
    }
    numberOfOpenAccounts=0;
}
