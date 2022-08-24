/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Maikel Mirzadegan
	ID     : 032299158
	Email  : mmirzadegan@senecacollege.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define WISHLIST_ITEMS 10
#include <stdio.h>
#include <stdlib.h>

int main()
{
	const double minNetIncome = 500.00; // variable for minimum income
	const double maxNetIncome = 400000.00;  // variable for max income
	double income = 0; // income
	int numOfForecast=0; // variables for forecast items
	int priority[WISHLIST_ITEMS]; // variable for priority of items
	double cost[WISHLIST_ITEMS]; // Variable for cost of items
	char financeOptions[WISHLIST_ITEMS+1]; // variable for finance options
	int i; // counter
	double totalCost = 0; // variable for the total cost


	printf("+--------------------------+\n");
	printf("+ Wish List Forecaster	   |\n");
	printf("+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf_s("%lf", &income);
		if (income < minNetIncome)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		if (income > maxNetIncome)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}

	} while (!(income <= maxNetIncome && income >= minNetIncome));


	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf_s("%d", &numOfForecast);
		
		if (numOfForecast > WISHLIST_ITEMS || numOfForecast < 1)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		
	} while (!(numOfForecast <= WISHLIST_ITEMS && numOfForecast >= 1));

	
	for (i = 0; i < numOfForecast; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf_s("%lf", &cost[i]);

			if (cost[i] < 100)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}

		} while (!(cost[i] >= 100));

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]:");
			scanf_s("%d", &priority[i]);

			if (priority[i] < 1 || priority[i] >3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");

			}

		} while (priority[i] < 1 || priority[i] >3);


		do
			
		{

			printf("   Does this item have financing options? [y/n]:");
			scanf_s("\n%c", &financeOptions[i]);
			

			if (!(financeOptions[i] == 'y' || financeOptions[i] == 'n'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

			}

		} while (!(financeOptions[i] == 'y' || financeOptions[i] == 'n'));
		
	}
	

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < numOfForecast; i++)
	{

		printf("%3d  %5d   %5c    %11.2lf\n", i + 1, priority[i], financeOptions[i], cost[i]);
			
		totalCost += cost[i];
	
	}
	printf("---- -------- -------- -----------\n");
	printf("\t\t      $%11.2lf\n\n", totalCost);
	printf("Best of luck in all your future endeavours!");

	return 0;
}
