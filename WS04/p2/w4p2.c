/*
	==================================================
	Workshop #4 (Part-2):
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
#include <math.h>

int main()
{
	const double minNetIncome = 500.00;           // variable for minimum income
	const double maxNetIncome = 400000.00;       // variable for max income
	double income = 0;                          // income
	int numOfForecast = 0;                     // variables for forecast items
	int priority[WISHLIST_ITEMS];             // variable for priority of items
	double cost[WISHLIST_ITEMS];               // Variable for cost of items
	char financeOptions[WISHLIST_ITEMS + 1];   // variable for finance options
	int i;									  // counter
	double totalCost = 0;					 // variable for the total cost


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
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
		scanf("%d", &numOfForecast);

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
			scanf("%lf", &cost[i]);

			if (cost[i] < 100)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}

		} while (!(cost[i] >= 100));

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < 1 || priority[i] >3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");

			}

		} while (priority[i] < 1 || priority[i] >3);


		do

		{

			printf("   Does this item have financing options? [y/n]: ");
			scanf("\n%c", &financeOptions[i]);


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

		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOptions[i], cost[i]);

		totalCost += cost[i];

	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", totalCost);



	int holder = 0; //variable to hold user entered values
	int filter = 0;
	double priorityTotal = 0;
	int totalMonths = (int)(totalCost / income);


	double a = totalCost / income;
	int b = totalCost / income;

	if (a - b > 0) {

		totalMonths += 1;

	}
	int years = totalMonths / 12;
	int months = totalMonths % 12;

	int hasFinance = 0;

	do
	{
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &holder);

		if (holder == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n"); // [option-1]
			printf("Amount:   $%1.2lf\n", totalCost);
			printf("Forecast: %d years, %d months\n", years, months);
			printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.");
			printf("\n====================================================\n");


		}
		else if (holder == 2)
		{


			do

			{

				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &filter);
				printf("\n====================================================\n");


				if (!(filter >= 1 && filter <= 3))
				{

					printf("\nERROR: Invalid menu selection.\n");
				}


			} while (!(filter >= 1 && filter <= 3));


			priorityTotal = 0;
			hasFinance = 0;

			printf("Filter:   by priority (%d)\n", filter);

			for (i = 0; i < numOfForecast; i++) {
				if (priority[i] == filter) {

					priorityTotal += cost[i];
					if (financeOptions[i] == 'y') {
						hasFinance = 1;

					}
				}


			}






			totalMonths = (int)(priorityTotal / income);
			a = priorityTotal / income;
			b = priorityTotal / income;

			if (a - b > 0) {

				totalMonths += 1;

			}
			years = totalMonths / 12;
			months = totalMonths % 12;

			printf("Amount:   $%.2lf\n", priorityTotal);
			printf("Forecast: %d years, %d months\n", years, months);

			if (hasFinance == 1) {
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.");
			}
			printf("\n====================================================\n");

		}
		else if (holder == 3)
		{
			printf("\nERROR: Invalid menu selection.\n");

		}



	} while (holder >= 1 && holder <= 3);



	printf("\nBest of luck in all your future endeavours!\n");


	return 0;
}


