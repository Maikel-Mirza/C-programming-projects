/*
  *****************************************************************************
                            Workshop - #6 (Part-2)
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
#include <math.h>
#define MAXITEMS 10  // max number of items
#define MINITEMS 1  // min number of items

int main()
{

    const double MIN_INCOME = 500.0;    // setting the range of min income
    const double MAX_INCOME = 400000.0; // setting the range of max income
    const double minItemCost = 100.0; // an item must have a value of at least 100
    double priorityCost = 0; // stores the total accumulated cost by priority
    double totalCost = 0.0; // the total cost after adding cost of each item
    double monthlyNetIncome; // how much you make per month
    double cost[MAXITEMS]; // array of item cost with size MAXITEMS
    char financeOptions[MAXITEMS]; // array stores item finance options
    int priority[MAXITEMS]; // array of item priority with size MAXITEMS
    int continueLooping = 0; // flag for continuing most do while loops
    int howManyItems; // stores how many items the person wants to purchase
    int i; //flag is used in my for loop for iterating arrays for all items
    int selection; // do-while loop, stores how user wants to filter wishlist
    int priorityFilter; // what priority user wants to filter by
    int years; // how many years it will take
    int months; // how many months it will take
    int totalMonths = 0; // used for determining years and months
    int hasFinance = 0; // boolean for printing note if finance options were chosen

    printf("+--------------------------+\n"); // prints wish list banner
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do // determines users monthly income
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyNetIncome);

        if (monthlyNetIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income"
                " of at least $500.00\n\n");
        }
        else if (monthlyNetIncome > MAX_INCOME)
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
        scanf("%d", &howManyItems);

        if (howManyItems < MINITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else if (howManyItems > MAXITEMS)
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

    for (i = 0; i <= howManyItems - 1; i++)
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

for (i = 0; i <= howManyItems - 1; i++)
    {
    
    printf("%3d  %5d    %5c    %11.2lf\n",
        i + 1, priority[i], financeOptions[i], cost[i]);
        totalCost += cost[i]; // accumulate cost
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    
    // this is how I calculate the time it will take to pay off costs of items
    totalMonths = (int)ceil(totalCost / monthlyNetIncome);
    years = totalMonths / 12;
    months = totalMonths % 12;
   
    /* do-while loop holds iterations and selection constructs for filtering
    items by total cost, priority and if there are financing options. 0 exits */
    do
    {
        printf("How do you want to forecast your wish list?\n"); // menu options
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 1) // filters by total cost of all items
        {

            printf("\n====================================================\n");
            printf("Filter:   All items\n"); // [option-1]
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months", years, months);
            printf("\nNOTE: Financing options are available on some items.\n"
                "      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }
        if (selection == 2) // filters by priority level
        {
            do

            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFilter);
                printf("\n====================================================\n");

                if (!(priorityFilter >= 1 && priorityFilter <= 3))
                {   
                    //error if outside the range
                    printf("\nERROR: Invalid menu selection.\n\n");
                }


            } while (!(priorityFilter >= 1 && priorityFilter <= 3));

            priorityCost = 0; // setting variable to zero before used
            hasFinance = 0; // boolean for printing finance option note
            printf("Filter:   by priority (%d)\n", priorityFilter); // [option-2]

         /*for the array iterator loop, if priority[i] == priorityFilter
         then it accumulates the cost[i] */

            for (i = 0; i <= howManyItems - 1; i++) 
            {

                if (priority[i] == priorityFilter)
                {

                    priorityCost += cost[i]; // accumulates the cost by priority
                    if (financeOptions[i] == 'y')
                    {
                        hasFinance = 1; // sets hasFinance to true

                    }


                }
            }
             /* reusing totalMonths and years equations
             but this time filtering by priority */

            totalMonths = (int)ceil(priorityCost / monthlyNetIncome);
            years = totalMonths / 12;
            months = totalMonths % 12;
 
                printf("Amount:   $%1.2lf\n", priorityCost);
                printf("Forecast: %d years, %d months", years, months);
                if (hasFinance == 1) // if hasFiance = 1 it prints the note
                {
                    printf("\nNOTE: Financing options are available on some items.\n"
                           "      You can likely reduce the estimated months.");
                }
                printf("\n====================================================\n\n");
            
           
        }
        else if (!(selection >=0 && selection < 3)) // outside the range
        {
            printf("\nERROR: Invalid menu selection.\n\n");
        }

    } while (selection != 0); // runs while not equal to 0

    // final print statemtent 
    printf("\nBest of luck in all your future endeavours!\n\n"); 

    return 0;
}