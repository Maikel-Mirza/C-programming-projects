/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   : Maikel Mirzadegan
	ID     : 032299158
	Email  : mmirzadegan@senecacollege.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double num = 0;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf_s("%lf", &num);
	printf("Service fee (5.0 percent): %.2lf\n", num*0.05);
	printf("Balance to dispense: $%1.2lf\n\n", num - num*0.05);

	int numOfCents = (num - num * 0.05) * 100;
	int numOfToonies = numOfCents / 200;
	int centsRemaining = (int)numOfCents % 200;
	printf("$2.00 Toonies  X %d (remaining: $%1.2lf)\n", numOfToonies, (double)centsRemaining/100);
	
	int numOfLoonies = centsRemaining / 100;
	centsRemaining = (int)numOfCents % 100;
	printf("$1.00 Loonies  X %d (remaining: $%1.2lf)\n", numOfLoonies, (double)centsRemaining/100);
	int numOfQuarters = centsRemaining / 25;
	centsRemaining = (int)centsRemaining % 25;
	printf("$0.25 Quarters X %d (remaining: $%1.2lf)\n", numOfQuarters, (double)centsRemaining/100);
	int numOfDimes = centsRemaining / 10;
	centsRemaining = (int)centsRemaining % 10;
	printf("$0.10 Dimes    X %d (remaining: $%1.2lf)\n", numOfDimes, (double)centsRemaining/100);
	int numOfNickels = centsRemaining / 5;
	centsRemaining = (int)centsRemaining % 5;
	printf("$0.05 Nickels  X %d (remaining: $%1.2lf)\n", numOfNickels, (double)centsRemaining/100);
	int numOfPennies = centsRemaining / 1;
	centsRemaining = (int)centsRemaining % 1;
	printf("$0.01 Pennies  X %d (remaining: $%1.2lf)\n\n", numOfPennies, (double)centsRemaining/100);
	printf("All coins dispensed!");
	


	return 0;
}

