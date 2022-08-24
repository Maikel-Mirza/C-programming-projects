/*
  *****************************************************************************
                            Workshop - #6 (Part-1)
  Full Name  :    Maikel Mirzadegan
  Student ID#:    032299158
  Email      :    mmirzadegan@senecacollege.ca
  Section    :    NPP


  Authenticity Declaration:
  I declare this submission is the result of my own work and has not been
  shared with any other student or 3rd party content provider. This submitted
  piece of work is entirely of my own creation.
  *****************************************************************************
*/
#include <stdio.h>
#define MAXITEMS 10 // max number of items
#define MINITEMS 1 // min number of items

int main()
{

    const double minMonthlyIncome = 500.00;    // setting the range of min income
    const double maxMonthlyIncome = 400000.00; // setting the range of max income
    const double minItemCost = 100.00; // an item must have a value of at least 100
    double totalCost = 0.0; // the total cost after adding cost of each item
    double monthlyNetIncome; // how much you make per month
    double cost[MAXITEMS]; // array of item cost with size MAXITEMS
    int priority[MAXITEMS]; // array of item priority with size MAXITEMS
    char financeOptions[MAXITEMS]; // array stores item finance options
    int continueLooping = 0; // flag for continuing all do while loops
    int numOfItems; // stores how many items the person wants to purchase
    int i; //flag is used in my for loop for iterating arrays for all items

    printf("+--------------------------+\n"); // prints wish list banner
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do // determines users monthly income
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyNetIncome);

        if (monthlyNetIncome < minMonthlyIncome)
        {
            printf("ERROR: You must have a consistent monthly income"
                   " of at least $500.00\n\n");
        }
        else if (monthlyNetIncome > maxMonthlyIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value"
                   " no more than $400000.00\n\n");
        }
        else
        {
            printf("\n");
            continueLooping = 1; // here it exits the loop
        }

    } while (continueLooping == 0);

    do // determines users number of desired items
    {
        continueLooping = 0; // reusing flag
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);

        if (numOfItems < MINITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else if (numOfItems > MAXITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else
        {
            continueLooping = 1; // exits the loop
        }

    } while (continueLooping == 0);

    printf("\n");

    /* this nested for loop stores 3 arrays (cost, priority, 
    financeOptions), it iterates for all the items */

    for (i = 0; i <= numOfItems - 1; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        // cost array loop that is for setting cost of items
        do
        {
            continueLooping = 0; //reusing flag
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minItemCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                continueLooping = 1; // exits the loop
            }

        } while (continueLooping == 0);

        // priority array loop that is for determining priority level of items
        do
        {
            continueLooping = 0; // reusing flag
            printf("   How important is it to you? "
                   "[1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else if (priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                continueLooping = 1; // exits the loop
            }

        } while (continueLooping == 0);

        // financeOptions array loop for determining if user wants to finance items
        do
        {
            continueLooping = 0; // reusing flag
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOptions[i]);

            if (financeOptions[i] == 'N')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else if (financeOptions[i] == 'Y')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else if (financeOptions[i] != 'y' && financeOptions[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                continueLooping = 1; // exits the loop
            }

        } while (continueLooping == 0);
        printf("\n");
    }
    numOfItems = 1; // so I can print number of items from 1-3
    totalCost = cost[0] + cost[1] + cost[2]; // adds all costs together

    /* summary displays total cost of all items, priority, finance options
    and cost at each element of the array */  

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    printf("%3d  %5d    %5c    %11.2lf\n",
           numOfItems, priority[0], financeOptions[0], cost[0]);
    printf("%3d  %5d    %5c    %11.2lf\n",
           numOfItems + 1, priority[1], financeOptions[1], cost[1]);
    printf("%3d  %5d    %5c    %11.2lf\n",
           numOfItems + 2, priority[2], financeOptions[2], cost[2]);
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}