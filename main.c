
#include <stdio.h>
#include "myBank.h"
/*
the program 


*/
int main ()
{
    char option=' ';
    double doubleNumber=0;
    int accountNumber=0;
    do
    {
        printf("\nPlease choose a transaction type:\n");
        printf("O-Open Account\n");
        printf("B-Balance Inquiry\n");
        printf("D-Deposit\n");
        printf("W-Withdrawal\n");
        printf("C-Close Account\n");
        printf("I-Interest\n");
        printf("P-Print\n");
        printf("E-Exit\n");
        while(option==' ')
        {  option=getchar();}
        switch (option)
            {
                case 'O':
                    printf("Please enter amount for deposit: ");
                    if(scanf("%lf",&doubleNumber)!=1)
                    { 
                        getchar();
                        printf("Failed to read the amount\n");
                    }
                    else
                    {
                        openAccount(doubleNumber);
                    }
                    break;
                case 'B':
                    printf("Please enter account number: ");
                    if(scanf("%d",&accountNumber)!=1)
                    { 
                        getchar();
                        printf("Failed to read the account number\n");
                    }
                    else
                    {
                        balance(accountNumber);
                    }
                    break;


                case 'D':
                    printf("Please enter account number: ");
                    if(scanf("%d",&accountNumber)!=1)
                    { 
                        getchar();
                        printf("Failed to read the account number\n");
                    }else
                    {
                        printf("Please enter amount for deposit: ");
                        if(scanf("%lf",&doubleNumber)!=1)
                        { 
                           getchar();
                           printf("Failed to read the amount\n");
                        }
                        else
                        {
                            deposite(accountNumber,doubleNumber);
                        }
                    }           
                    break;



                case 'W':
                    printf("Please enter account number: ");
                    if(scanf("%d",&accountNumber)!=1)
                    { 
                        getchar();
                        printf("Failed to read the account number\n");
                    }else
                    {
                        printf("Please enter the amount to withdraw: ");
                        if(scanf("%lf",&doubleNumber)!=1)
                        { 
                           getchar();
                           printf("Failed to read the amount\n");
                        }
                        else
                        {
                            withdraw(accountNumber,doubleNumber);
                        }
                    } 
                    break;




                case 'C':
                    printf("Please enter account number: ");
                    if(scanf("%d",&accountNumber)!=1)
                    { 
                        getchar();
                        printf("Failed to read the account number\n");
                    }
                    else
                    {
                        close(accountNumber);
                    }
                    break;




                case 'I':
                    printf("Please enter interest rate: ");
                    if(scanf("%lf",&doubleNumber)!=1)
                    { 
                           getchar();
                           printf("Failed to read the interest rate\n");
                    }
                    else
                    {
                        addIntrest(doubleNumber);
                    }
                    break;


                case 'P':
                    printAll();
                    break;


                case 'E':
                    closeAll();
                    break;



                default:
                    printf("Invalid transaction type\n");//different letter
                    break;
            }
            
    } while (option!='E');
    

    return 0;
}