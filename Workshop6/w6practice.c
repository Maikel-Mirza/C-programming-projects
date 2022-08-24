#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAXITEMS 10  // max number of items
#define MINITEMS 1  // min number of items

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

    int selection;
    int priorityFinanced;
    double amount;
    int years;
    int months;
    double priorityCost = 0;

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

    /* summary displays total cost of all items, priority, finance options
    and cost at each element of the array */

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
for (i = 0; i <= numOfItems - 1; i++)
    {
    
    printf("%3d  %5d    %5c    %11.2lf\n",
        i + 1, priority[i], financeOptions[i], cost[i]);
        totalCost += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    
    int totalMonths = (int)ceil(totalCost / monthlyNetIncome);
    years = totalMonths / 12;
    months = totalMonths % 12;
    int hasFinance = 0;

    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 1)
        {

            printf("\n====================================================\n");
            printf("Filter:   All items\n"); // [option-1]
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months", years, months);
            printf("\nNOTE: Financing options are available on some items.\n"
                "      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
        else if (selection == 2)
        {
            do

            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFinanced);
                printf("\n====================================================\n");

                if (!(priorityFinanced >= 1 && priorityFinanced <= 3))
                {
                    printf("\nERROR: Invalid menu selection.\n\n");
                }


            } while (!(priorityFinanced >= 1 && priorityFinanced <= 3));

            priorityCost = 0;
            hasFinance = 0;
            printf("Filter:   by priority (%d)\n", priorityFinanced); // [option-1]

            for (i = 0; i <= numOfItems - 1; i++)
            {

                if (priority[i] == priorityFinanced)
                {

                    priorityCost += cost[i];
                    if (financeOptions[i] == 'y')
                    {
                        hasFinance = 1;

                    }


                }
            }

            totalMonths = (int)ceil(priorityCost / monthlyNetIncome);
            years = totalMonths / 12;
            months = totalMonths % 12;
 
                printf("Amount:   $%1.2lf\n", priorityCost);
                printf("Forecast: %d years, %d months", years, months);
                if (hasFinance == 1)
                {
                    printf("\nNOTE: Financing options are available on some items.\n"
                           "      You can likely reduce the estimated months.");
                }
                printf("\n====================================================\n\n");
            
           
        }
        else if (selection == 3)
        {
            printf("\nERROR: Invalid menu selection.\n\n");

        } 

    } while (selection >= 1 && selection <= 3);

    printf("\nBest of luck in all your future endeavours!\n\n");

    return 0;
}