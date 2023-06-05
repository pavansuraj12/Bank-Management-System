#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void new_customer();
void customer_login();
void menu2();
void account_transaction();
void account_withdrawal();
void account_deposit();
void account_loan();
void homeloan();
void agricultureloan();
void personalloan();
void goldloan();
void menu3();
void maxtrans();
struct Account
{
	char name[50],password[50];int age;
	long long account_number;int tenure_fd;
	float deposit_amt,balance;long long mobile_num;
}account;
int i=0;float max=0,max1=0;
int main()
{
	int choice_1;
	system("cls");
	printf("\n\t\t  WLECOME TO PRAHARSHITA BANK\n");
	printf("\nCustomer Services\n");
	printf("Enter\n");
	printf("1---->For new user\n");
	printf("2---->For existing user\n");
	printf("3---->Exit\n");
	scanf("%d",&choice_1);
	switch(choice_1)
	{
		case 1:
			new_customer();
			break;
		case 2:
			customer_login();
			break;
		case 3:
			exit(0);
		default:
			printf("\nInvalid choice.Please try again./n");
			break;
	}
}
void new_customer()
{
	system("cls");
    FILE *fp=fopen("input.txt","w+");
    if(fp==NULL)
	{
		printf("Error opening file.\n");
		exit(0);
	}
    printf("Enter the name of the account holder: ");
	scanf("%s",&account.name);
	printf("Enter age of account holder: ");
	scanf("%d",&account.age);
	if(account.age<18)
	{
		printf("Age must be greater than 18");
		printf("\nTry Again");
		main();
	}
	printf("Enter the account number: ");
	scanf("%lld",&account.account_number);
	printf("Choose Password For your Account:");
	scanf("%s",&account.password);
	printf("Enter mobile number for holder: ");
	scanf("%lld",&account.mobile_num);
	printf("Enter amount deposited in the account :");
	scanf("%f",&account.deposit_amt);
	float balance=account.deposit_amt;
	fprintf(fp,"\n%s",account.name);
    fprintf(fp,"\n%s\n%d\n%lld\n%lld\n%f\n",account.password,account.age,account.account_number,account.mobile_num,account.deposit_amt,account.password);
	printf("\nAccount succeefully created.\n");
	printf("\nNow you can Login to your Account:\n");
	system("pause");
	fclose(fp);
	FILE *fp2=fopen("balance.txt","w+");
	fprintf(fp2,"%f",account.deposit_amt);
	fclose(fp2);
	main();
}
void customer_login()
{
	system("cls");
	char random[50],pass[50];
    printf("Enter the Name of the account Holder:");
    scanf("%s",&random);
	printf("\nEnter the Password:");
	scanf("%s",&pass);
    FILE *fp1=fopen("input.txt","a+");
	while(!feof(fp1))
	{
		char name[50];
			fscanf(fp1,"%s",&account.name);
			fscanf(fp1,"%s",&account.password);
    		fscanf(fp1,"%d",&account.age);
			fscanf(fp1,"%lld",&account.account_number);
    		fscanf(fp1,"%lld",&account.mobile_num);
    		fscanf(fp1,"%f",&account.balance);
		}
			if(strcmp(pass,account.password)==0)
			{
			system("cls");
			printf("The details of account are\n"); 
			printf("\nThe Name of The Account Holder:%s",account.name);
    		printf("\nAge of the Account Holder:%d",account.age);
			printf("\nAccount Number is %lld",account.account_number);
    		printf("\nMobile number of the Account Holder:%lld",account.mobile_num);
    		printf("\nBalance Amount in the Account:%f\n",account.balance);
			system("pause");
			menu2();
			fclose(fp1);
			}
			else
			{
				printf("!!!\tSomething went wrong");
				printf("\nCheck Your Password and Try Agian");
				customer_login();
			}
		FILE *fp4= fopen("balance.txt","w+");
		fprintf(fp4,"%f",account.balance);
		fclose(fp4);
	}
	void menu2()
	{
	system("cls");
	i=0;
    printf("\n\nEnter the choice of service you need\n");
	printf("\n1---->Transaction");
	printf("\n2---->Apply for Loan");
	printf("\n3---->Go back to Main menu");
	printf("\n4---->Exit");
    int choice_3;
	scanf("%d",&choice_3);
	switch(choice_3)
	{
		case 1:
			account_transaction();
			break;
		case 2:
			account_loan();
			break;
		case 3:
			main();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nInvalid choice.Please try again./n");
			break;
	}
}
void account_transaction()
{
	system("cls");
	if(i>4)
	maxtrans();
	printf("\n Enter the choice of transaction you need\n");
	printf("\n1----->Withdrawal");
	printf("\n2----->Deposit");
	printf("\n3----->Go back to previous Menu");
	int choice_5;
	scanf("%d",&choice_5);
	switch(choice_5)
	{
		case 1:
			account_withdrawal();
			break;
		case 2:
			account_deposit();
			break;
		case 3:
			menu2();
			break;
		default:
			printf("Invalid Input");
			break;
	}
	}
void maxtrans()
	{
	printf("\n!!! Limit Exceeded !!!!");
	printf("\nMax Number of Transactions is 5\n");
	getch();
	printf("\nEnter\n1--->Go back to Main Menu\n2--->Exit");
	int ch6;
	scanf("%d",&ch6);
	switch(ch6)
	{
		case 1:
			main();
			break;
		case 2:
			exit(0);
		default:
			printf("Invalid choice\nExiting from program");
	}
	}
void account_withdrawal()
{
	float amount_1;
	FILE *fp3=fopen("balance.txt","w+");
	if(fp3==NULL)
	fscanf(fp3,"%f",&account.balance);
	printf("Enter amount to withdrawal:");
	scanf("%f",&amount_1);
	max+=amount_1;
	if(amount_1>account.balance)
	{
		printf("Insufficent balance");
		getch();
	}
	else if(max>200001)
	{
		printf("!!!\tLimit reached\n");
		printf("Maximum Amount of Transaction is only 200000(2 Lakh)");
		printf("\nPlease Try Again");
		getch();
		account_transaction();
	}
	else
	{
		printf("Balance Amount in the Account : %f\n",account.balance);
		account.balance=account.balance-amount_1;
		printf("Balance Amount after the transaction is %f\n",account.balance);
		i++;
		printf("%d\t",i);
		printf("%f",max);
		getch();
	}
	fprintf(fp3,"%f",account.balance);
	fclose(fp3);
	account_transaction();
}
void account_deposit()
{
	float amount_2;
	FILE *fp6=fopen("balance.txt","w+");
	fscanf(fp6,"%f",&account.deposit_amt);
	printf("Enter the Amount to be Deposited:");
	scanf("%f",&amount_2);
	max1=max1+amount_2;
	if(max1>200000)
	{
		printf("!!!\tLimit reached\n");
		printf("Maximum Amount of Transaction is only 200000(2 Lakh)");
		printf("\nPlease Try Again");
		getch();
		account_transaction();
	}
	else
	{
	printf("Balance Amount in the Account : %f\n",account.balance);
	account.balance= account.balance +amount_2;
	printf("Balance Amount after the transaction is %f\n",account.balance);
	fprintf(fp6,"%f",account.balance);
	i++;
	printf("%d\t",i);
	printf("%f",max1);
	getch();
	fclose(fp6);
	account_transaction();
	}
}
void account_loan()
{
	system("cls");
	int creditscore,ch5;
	char name[50],pass1[50];
	printf("\n\t\tCredit Eligibiliy\n");
	FILE *fp7=fopen("input.txt","r+");
	printf("\nEnter Your Name:");
	scanf("%s",&name);
	printf("\nEnter Your Password:");
	scanf("%s",&pass1);
	fscanf(fp7,"%s",&account.name);
	fgets(account.name,50,fp7);
	printf("%s",account.password);
	if(strcmp(pass1,account.password)==0)
	{
	printf("\nEnter Your cibil score :");
	scanf("\n%d",&creditscore);
	if(creditscore<70)
	{
		printf("Cibil must be greater than 70 for taking loan\n");
		printf("Sorry,You are not Eligible for Loan");
		menu3();
	}
	else if(creditscore>=70)
	    {
	        printf("Select your choice of loan needed");
		    printf("\n1--->Home loan\n2--->Agriculture loan\n3--->Personal loan\n4--->Gold Loan\n5--->Exit");
	    }
	    scanf("%d",&ch5);
		switch(ch5)
		{
			case 1 :
				homeloan();
				break;
			case 2 :
				agricultureloan();
				break;
			case 3 :
				personalloan();
				break;
			case 4:
				goldloan();
			case 5 :
				exit(0);
				break;
			default:
				printf("");
		}
	}
	else
	{
		printf("!!!\tSomething went wrong");
		printf("Check Your Password and Try Agian");
	}
	fclose(fp7);

}
void homeloan()
{
	FILE *fp8= fopen("loan.txt","w+");
	system("cls");
	int tenure;
	float loanamt1,intr,loanamt2,emi;
	printf("Enter the loan amount needed: \n");
	scanf("\n%f",&loanamt1);
	printf("Enter the Tenure: ");
	scanf("\n%d",&tenure);
	printf("\nYour intrest rate will be 6.80 per year");
	intr=(loanamt1*6.80*tenure)/100;
	loanamt2=loanamt1+intr;
	emi=loanamt2/(tenure*12);
	account.balance+=loanamt2;
	getch();
	printf("\nYou have to pay %f amount by end",loanamt2);
	printf("\nYour montly EMI will be %f",emi);
	printf("\n***Loan Successfully Sanctioned***");
	printf("\n Your loan amount has been credited to your account");
	fprintf(fp8,"\nLoan:%f\nTenure:%d\nIntrest:%f\nEMI:%f",loanamt1,tenure,intr,emi);
	fclose(fp8);
	menu3();
}
void agricultureloan()
{
	FILE *fp9= fopen("loan.txt","w+");
	system("cls");
	float loanamt=0,acr;
	printf("Enter number of acres you have: ");
	scanf("\n%f",&acr);
	loanamt=acr*50000;
	printf("\nYou will get %f amount for this loan",loanamt);
	printf("\nYour intrest rate will be 3.50 per year");
	loanamt=(loanamt*3.5)/100;
	account.deposit_amt+=loanamt;
	getch();
	printf("\n You have to pay %f amount after the selling the product",loanamt);
	printf("\n***Loan Successfully Sanctioned***");
	printf("\n Your loan amount has been credited to your account");
	fprintf(fp9,"\nAcres:%dAmount:%f",acr,loanamt);
	fclose(fp9);
	menu3();
}
void personalloan()
{
	FILE *fp10= fopen("loan.txt","w+");
	system("cls");
	int tenure;float loanamt=0,intr=0,emi=0;
	printf("Enter the loan amount needed: ");
	scanf("\n%f",&loanamt);
	printf("\nEnter the tenure you would pay it back to the bank: ");
	scanf("\n%d",&tenure);
	printf("\nYour intrest rate will be 12.90 per year");
	intr=(loanamt*12.90*tenure)/100;
	loanamt+=intr;
	emi=loanamt/(tenure*12);
	account.deposit_amt+=loanamt;
	getch();
	printf("\n You have to pay %f amount by end",loanamt);
	printf("\n Your montly EMI will be %f",emi);
	printf("\n***Loan Successfully Sanctioned***");
	printf("\n Your loan amount has been credited to your account");
	fprintf(fp10,"\nLoan:%f\nTenure:%d\nIntrest:%f\nEMI:%f",loanamt,tenure,intr,emi);
	fclose(fp10);
	menu3();
}
void goldloan()
{
	FILE *fp11= fopen("loan.txt","w+");
	system("cls");
	float wggold,intr,loanamt=0;
	printf("Enter the weight of the gold(in gms) you are keeping as collatrel:");
	scanf("%f",&wggold);
	loanamt=(wggold/10)*35000;
	printf("\nYou will get %f loan amount: ",loanamt);
	intr=(loanamt*9.20)/100;
	loanamt+=intr;
	account.deposit_amt+=loanamt;
	getch();
	printf("\nYou have to pay back %f amount by 1 year",loanamt);
	printf("\n***Loan Successfully Sanctioned***");
	printf("\n Your loan amount has been credited to your account");
	fprintf(fp11,"\nLoan:%f\nGold:%d\nAmount:%f",loanamt,wggold,loanamt);
	fclose(fp11);
	menu3();
}
void menu3()
{
	getch();
	printf("\nEnter\n 1--->Go back to Previous Menu\n 2--->Exit");
	int ch5;
	scanf("%d",&ch5);
	switch(ch5)
	{
		case 1:
			account_loan();
			break;
		case 2:
			exit(0);
		default:
			printf("Invalid choice");
			menu3();
}
}
