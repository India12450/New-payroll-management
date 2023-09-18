#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to represent a bank account
struct BankAccount
{
    int accountNumber;
    char accountHolder[50];
    double balance;
};

// Function to perform admin login
int adminLogin()
{
    char username[20], password[20];
    clrscr();
	    printf("\n\t _________________________________________________________");
	    printf("\n\t|                                                         |");
	    printf("\n\t|                 	BANKING SYSTEM                    |");
	    printf("\n\t|_________________________________________________________|");

	    printf("\n\n");
	    printf("\n\t*=======================================================*\n");
	    printf("\n\t           |            ADMIN LOGIN           |           \n");
	    printf("\n\t                   Enter username:");
	    scanf("%s", username);
	    printf("\n\t                   Enter password:");
	    scanf("%s", password);
	    printf("\n\t---------------------------------------------------------\n");

	    // Predefined admin credentials
	    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
		{
			  printf("\n\n");
			  printf("\n\t*=======================================================*\n");
			  printf("\n\t           |     Admin Login Successful    |               \n");
			  printf("\n\t*=======================================================*\n");
			  getch();
			  return 1; // Successful login
		}
	   else
		{
			printf("\n\n");
			printf("\n\t*=======================================================*\n");
			printf("\n\t           |     Admin Login Failed!       |               \n");
			printf("\n\t*=======================================================*\n");
			getch();
			return 0; // Failed login
		}
}

// Function to create a new bank account
int createAccount(struct BankAccount *accounts, int *accountCount)
{
    clrscr();
	if (*accountCount >= 10)
	     {
		printf("\n\n");
		printf("\n\t*=======================================================*\n");
		printf("\n\t           |      Account limit reached.	     |         ");
		printf("\n\t           |      Cannot create more accounts.   |         \n");
		printf("\n\t*=======================================================*\n");
		return 0;
	     }
	    printf("\n\t _________________________________________________________");
	    printf("\n\t|                                                         |");
	    printf("\n\t|                 	BANKING SYSTEM                    |");
	    printf("\n\t|_________________________________________________________|");
	    printf("\n\n");
	    printf("\n\t*=======================================================*\n");
	    printf("\n\t           |          Create Account          |           \n");
	    printf("\n\t                  Enter account number:");
	    scanf("%d", &accounts[*accountCount].accountNumber);
	    printf("\n\t               Enter account holder's name:");
	    scanf("%s", accounts[*accountCount].accountHolder);
	    printf("\n\t                 Enter initial balance: ");
	    scanf("%lf", &accounts[*accountCount].balance);
	    printf("\n\t---------------------------------------------------------");

	(*accountCount)++;
	printf("\n\n");
	printf("\n\t*=======================================================*\n");
	printf("\n\t           |     Account Created Successfully    |         \n");
	printf("\n\t*=======================================================*\n");

    getch();
    return 1;
}

// Function to deposit money
void deposit(struct BankAccount *account, double amount)
{
    clrscr();
	account->balance += amount;
	    printf("\n\t _________________________________________________________");
	    printf("\n\t|                                                         |");
	    printf("\n\t|                 	BANKING SYSTEM                    |");
	    printf("\n\t|_________________________________________________________|");

	    printf("\n\n");
	    printf("\n\t*=======================================================*\n");
	    printf("\n\t           |            DEPOSIT           |                ");
	    printf("\n\t                                                           ");
	    printf("\n\t                 Deposited %.2lf.                          ", amount);
	    printf("\n\t                 New balance: %.2lf.                       ", account->balance);
	    printf("\n\t                                                           ");
	    printf("\n\t---------------------------------------------------------");
    getch();
}

// Function to withdraw money
void withdraw(struct BankAccount *account, double amount)
{
    clrscr();
	if (amount > account->balance)
	{
	     printf("\n\n");
	     printf("\n\t*=======================================================*\n");
	     printf("\n\t           |         Insufficient Balance        |         \n");
	     printf("\n\t*=======================================================*\n");
	}
	else
	{
	     account->balance -= amount;
	     printf("\n\t _________________________________________________________");
	     printf("\n\t|                                                         |");
	     printf("\n\t|                 	BANKING SYSTEM                    |");
	     printf("\n\t|_________________________________________________________|");
	     printf("\n\n");
	     printf("\n\t*=======================================================*\n");
	     printf("\n\t           |           WITHDRAW           |                ");
	     printf("\n\t                                                          ");
	     printf("\n\t                Withdrawn %.2lf.                           ", amount);
	     printf("\n\t                New balance: %.2lf.                        ", account->balance);
	     printf("\n\t                                                           ");
	     printf("\n\t---------------------------------------------------------");
	}
    getch();
}

// Function to check account balance
void checkBalance(struct BankAccount *account)
{
    clrscr();
	  printf("\n\t _________________________________________________________");
	  printf("\n\t|                                                         |");
	  printf("\n\t|                 	BANKING SYSTEM                    |");
	  printf("\n\t|_________________________________________________________|");
	  printf("\n\n");
	  printf("\n\t*=======================================================*\n");
	  printf("\n\t           |           Account Details         |           ");
	  printf("\n\t                                                           ");
	  printf("\n\t                Account Holder: %s                         ", account->accountHolder);
	  printf("\n\t                Account Number: %d                         ", account->accountNumber);
	  printf("\n\t                Balance: %.2lf                             ", account->balance);
	  printf("\n\t                                                           ");
	  printf("\n\t---------------------------------------------------------");
    getch();
}
// main program body
void main()
{
    int choice;
    struct BankAccount accounts[10]; // Array to store multiple accounts
    int accountCount = 0;
    int loggedIn = 0;
    int accountNumber;
    int found;
    int i;
    int operation;
    double depositAmount;
    double withdrawAmount;
    clrscr();


	while (1)
	{
	    clrscr();
	    printf("\n\t _________________________________________________________");
	    printf("\n\t|                                                         |");
	    printf("\n\t|                 	BANKING SYSTEM                    |");
	    printf("\n\t|_________________________________________________________|");

	    printf("\n\n");
	    printf("\n\t*=======================================================*\n");
	    printf("\n\t           |        1 : ADMIN LOGIN           |           \n");
	    printf("\n\t           |        2 : CREATE ACCOUNT	      |           \n");
	    printf("\n\t           |        3 : CUSTOMER MENU         |           \n");
	    printf("\n\t           |        4 : EXIT                  |           \n");
	    printf("\n\t------------------------------------------------------------");

	    printf("\n\t\t                Enter your choice: ");
	    scanf("%d", &choice);

	    switch (choice)
	    {
	       case 1:  // Admin Login Function
		     if (adminLogin())
		     {
			 loggedIn = 1;
		     }
		     break;

	       case 2:  // Create Account Function
		     if (loggedIn)
		     {
			 if (createAccount(accounts, &accountCount))
			 {
				// Account creation successful
			 }
		     }
		     else
		     {
			printf("\n\n");
			printf("\n\t*=======================================================*\n");
			printf("\n\t           |   Please Login As Admin First !     |         \n");
			printf("\n\t*=======================================================*\n");
		     }
		     break;

	       case 3:  // Customer Menu
		     if (loggedIn)
		     {
			printf("\n\n");
			printf("\n\t*=======================================================*\n");
			printf("\n\t             Enter Account Number:");
			scanf("%d", &accountNumber);
			printf("\n\n\t*=======================================================*\n");

			 clrscr();
			 found = 0;
			 for (i = 0; i < accountCount; i++)
			 {
			     if (accounts[i].accountNumber == accountNumber)
			     {
				 found = 1;
				 printf("\n\t _________________________________________________________");
				 printf("\n\t|                                                         |");
				 printf("\n\t|                 	BANKING SYSTEM                    |");
				 printf("\n\t|_________________________________________________________|");
				 printf("\n\n");
				 printf("\n\t*=======================================================*\n");
				 printf("\n\t           |          CUSTOMER MENU           |           \n");
				 printf("\n\t           |        1 : DEPOSIT     	      |           \n");
				 printf("\n\t           |        2 : WITHDRAW              |           \n");
				 printf("\n\t           |        3 : CHECK BALANCE         |           \n");
				 printf("\n\t------------------------------------------------------------");
				 printf("\n\t\t                Enter your choice: ");
				 scanf("%d", &operation);

				 switch (operation)
				 {
				    case 1: // Deposit Function
					  printf("\n\n");
					  printf("\n\t*=======================================================*\n");
					  printf("\n\t             Enter Deposit Amount:");
					  scanf("%lf", &depositAmount);
					  printf("\n\n\t*=======================================================*\n");

					  deposit(&accounts[i], depositAmount);
					  break;
				    case 2: // Withdraw Function
					  printf("\n\n");
					  printf("\n\t*=======================================================*\n");
					  printf("\n\t             Enter Withdraw Amount:");
					  scanf("%lf", &withdrawAmount);
					  printf("\n\n\t*=======================================================*\n");

					  withdraw(&accounts[i], withdrawAmount);
					  break;
				    case 3: // Check Balance Function
					  checkBalance(&accounts[i]);
					  break;
				    default:
					   printf("\n\n");
					   printf("\n\t*=======================================================*\n");
					   printf("\n\t             |       Invalid Choice !       |            ");
					   printf("\n\n\t*=======================================================*\n");
				 }
				 break;
			     }
			 }

			 if (!found)
			 {
			     printf("\n\n");
			     printf("\n\t*=======================================================*\n");
			     printf("\n\t           |         Acoount Not Found !         |         \n");
			     printf("\n\t*=======================================================*\n");
			 }
		     }
		     else
		     {
			printf("\n\n");
			printf("\n\t*=======================================================*\n");
			printf("\n\t           |   Please Login As Admin First !     |         \n");
			printf("\n\t*=======================================================*\n");
		     }
		     break;

	       case 4:
		     printf("\n\n");
		     printf("\n\t*=======================================================*\n");
		     printf("\n\t           |         Exiting Program.            |         ");
		     printf("\n\t           |            Thank You                |         ");
		     printf("\n\t*=======================================================*\n");
		     getch();
		     return 0;
	       default:
		      printf("\n\n");
		      printf("\n\t*=======================================================*\n");
		      printf("\n\t           |         Invalid Choice !            |         \n");
		      printf("\n\t*=======================================================*\n");
		      getch();
		      return 0;
	    }
	}

    getch();
}
