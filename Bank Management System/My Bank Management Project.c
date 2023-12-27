#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

struct date {
	int month,day,year;
};

struct accountData{
		char name[100];
		int acc_no[14];
		int balance[100];
		struct date acc_open_date;
		char citizenship[20];
		char contact_no[10];
		char email_id[40];
	}add;
	
struct accountData Accounts[100];
int num_acc=100;


void login();
void login() 
{
    char username[50], password[50];
    struct User registereduser1 = {"Nishant", "851211"};
    struct User registereduser2 = {"Deepak", "800005"};

    printf("\t\tWelcome to Patna Corporate Bank\n\t\t\t    Login\n\n");
	printf("\t\tEnter username: ");
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("\t\tEnter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(username, registereduser1.username) == 0 &&
        strcmp(password, registereduser1.password) == 0 ||
		strcmp(username, registereduser2.username) == 0 &&
        strcmp(password, registereduser2.password) == 0) 
	{
        printf("Login successful!\nWelcome to the Bank");
		homepage();
    } else 
	{
        system("cls");  // Clear the screen
        printf("\t\t  Invalid username or password\n\n");
		login();
    } 
}

int main() 
{
    login();
    return 0;
}


int homepage()
{
    system("cls");
    printf("\n\t\t------------------------------------\n");
    printf("\n\t\t       BANK MANAGEMENT SYSTEM       \n");
    printf("\n\t\t----------------------------------- \n");
    printf("\n\n\t\t1. Add Bank Account\n");
    printf("\t\t2. Withdraw\n");
    printf("\t\t3. Deposit\n");
    printf("\t\t4. Check Bank Balance\n");
    printf("\t\t5. Update Data of an Existing Account\n");
    printf("\t\t6. Show all Data\n");
    printf("\t\t7. Delete Existing Account\n");
    printf("\t\t8. Logout\n");
    printf("\n\n\t\tEnter what action you'd like to perform: ");

    int action;
    scanf("%d", &action);
	
	switch (action) 
	{
    case 1:
        addAC();
        break;
        
	case 2:
        withdraw();
        break;
	
    case 3:
        deposit();
        break;
        
	case 4:
        chkBalnc();
        break;
	
    case 5:
        updateAC();
        break;
        
    case 6:
        showData();
        break;
        
    case 7:
    	deleteAC();
    	
    case 8:
		printf("Logging out...\n");
        exit(0);
        
    default:
    	system("cls");
        printf("Invalid action. Please try again.\n");
        homepage();
        
	}
}
	
int addAC() 
{
    system("cls");
	
	printf("Enter your Full Name: ");
    scanf("%s",add.name);

    printf("Enter Account Number (14 digits): ");
	scanf("%d",&add.acc_no);

    printf("Enter Total Balance: ");
    scanf("%d", &add.balance);

    printf("Enter Account Opening Date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &add.acc_open_date.month,&add.acc_open_date.day,&add.acc_open_date.year);

    printf("Enter your Citizenship: ");
	scanf("%s",&add.citizenship);

    printf("Enter your Contact Number: ");
    scanf("%s",&add.contact_no);

    printf("Enter your Email ID: ");
    scanf("%s",&add.email_id);

    printf("Account added successfully!\n");
	
	int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
    return;
}


int withdraw(int acc_num, int amount) 
{
    system("cls");
	
	printf("\n\t\tEnter your 14 digit Account Number: ");
    scanf("%d",&acc_num);
    
    printf("\n\t\tEnter the Amount: ");
    scanf("%d",&amount);
    
	int i;
    // Find the account using Linear Search
    for (i = 0; i < num_acc; i++) 
	{
        if (*(Accounts[i].acc_no) == acc_num) 
		{
            // Account found
            if (amount > *(Accounts[i].balance)) 
			{
                printf("Insufficient funds.\n");
                return 0;
            } else {
                *(Accounts[i].balance) -= amount;
                printf("Withdrawal successful.\n");
                printf("New balance: %.2f\n", Accounts[i].balance);
                return 1;
            }
        }
    }
    

    // Account not found
    printf("\t\tAccount not found.\n");
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
    return 0;
}


int deposit(int acc_num, int amount) 
{
    system("cls");
	
	printf("\n\t\tEnter your 14 digit Account Number: ");
    scanf("%d",&acc_num);
    
    printf("\n\t\tEnter the Amount: ");
    scanf("%d",&amount);
	
	// Find the account using Linear Search
    int i;
	for (i = 0; i < num_acc; i++) 
	{
        if (*(Accounts[i].acc_no) == acc_num) 
            // Account found
                *(Accounts[i].balance)+= amount;
                printf("Withdrawal successful.\n");
                printf("New balance: %.2f\n", Accounts[i].balance);
                return 1;
    }

    // Account not found
    printf("\t\tAccount not found.\n");
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
}


int chkBalnc(int acc_num) {
    
	system("cls");
	
	printf("\n\t\tEnter your 14 digit Account Number: ");
    scanf("%d",&acc_num);
	
	int i;

    // Find the account using Linear Search
    for (i = 0; i < num_acc; i++) {
        if (*(Accounts[i].acc_no) == acc_num) {
            printf("Account balance: %.2f\n", Accounts[i].balance);  // Access the correct balance
            return 1;  // Indicate success
        }
    }

    // Account not found
    printf("\t\tAccount not found.\n");
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
    return 0;  // Indicate failure
}



int updateAC(int acc_num) {
    
	system("cls");
	
	printf("\n\t\tEnter your 14 digit Account Number: ");
    scanf("%d",&acc_num);
	
	int i;

    // Find the account
    for (i = 0; i < num_acc; i++) 
	{
        if (*(Accounts[i].acc_no) == acc_num) 
		{
            // Account found
            printf("Enter your Full Name: \n");
    		scanf("%s",add.name);

    		printf("Enter Account Number (14 digits): \n");
			scanf("%d",&add.acc_no);

    		printf("Enter Total Balance: \n");
    		scanf("%d", &add.balance);

    		printf("Enter Account Opening Date (MM/DD/YYYY): \n");
    		scanf("%d/%d/%d", &add.acc_open_date.month,&add.acc_open_date.day,&add.acc_open_date.year);

    		printf("Enter your Citizenship: \n");
			scanf("%s",&add.citizenship);

    		printf("Enter your Contact Number: \n");
    		scanf("%s",&add.contact_no);

    		printf("Enter your Email ID: \n");
    		scanf("%s",&add.email_id);

            printf("Record updated successfully.\n");
            return 1;
        }
    }

    // Account not found
    printf("\t\tAccount not found.\n");
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
	
    return 0;
}


int showData() {
    system("cls");
	printf("\n\t\t-----------------------------------\n");
    printf("\n\t\t       All Account Details         \n");
    printf("\n\t\t-----------------------------------\n");

    // Check if any accounts exist
    if (num_acc == 0) {
        printf("\n\t\tNo accounts found.\n");
        return;
    }

    // Print a header for the table
    printf("\n%-25s %-15s %-15s %-15s %-20s %-15s %-15s\n", "Name", "Account No.", "Balance", "Opening Date", "Citizenship", "Contact", "Email");

    // Using Loop to print data in tabular form
    int i;
	for ( i = 0; i < num_acc; i++) {
        printf("%-25s %-15d %-15d %02d/%02d/%4d %-20s %-15s %-15s\n",
               Accounts[i].name, Accounts[i].acc_no, Accounts[i].balance,
               Accounts[i].acc_open_date.month, Accounts[i].acc_open_date.day, Accounts[i].acc_open_date.year,
               Accounts[i].citizenship, Accounts[i].contact_no, Accounts[i].email_id);
    }
    printf("\n");
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
}


int deleteAC(int acc_num) {
    int i,j, found = 0;

    system("cls");
	
	printf("\n\t\tEnter your 14 digit Account Number: ");
    scanf("%d",&acc_num);
	
	// Find the account
    for (i = 0; i < num_acc; i++) {
        if (*(Accounts[i].acc_no) == acc_num) {
            found = 1;  // Account found

            // Shift remaining accounts to fill the gap
            for (j = i; j < num_acc - 1; j++) {
                Accounts[j] = Accounts[j + 1];
            }

            // Decrement the number of accounts
            num_acc--;

            printf("Account deleted successfully.\n");
            return 1;
        }
    }

    if (!found) 
	{
        printf("\t\tAccount not found.\n");
    }
    
    int lastaction;
	printf("\n\t\tTo proceed to Homepage, Enter 1\nTo Exit, Enter 0\n");
	scanf("%d",&lastaction);
	system("cls");
	if(lastaction==1)
	{
		homepage();
	}
	else if(lastaction==0)
	{
		exit(0);
	}
	else 
	{
		printf("Invalid Action");
	}
    return 0;
}

