/*
  *****************************************************************************
                            Workshop - #8 (P1)
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
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number)
{
    int num = 0;
    do
    {
        scanf("%d", &num);
        if (num < 1)
            printf("ERROR: Enter a positive value: ");
    } while (num < 1);
    if (number != NULL)
        *number = num;
    return num;
}
/*** This function is a do-while loop.
     If the number is negative, the message is printed and the loop continues.
     If the number is positive it is returned twice:
     through the return statement and through the dereferenced pointer.
     Be carefull, if the pointer is NULL, don't dereference it!
*/

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number1)
{
    double num;
    scanf("%lf", &num);
    while (true)
    {
        if (num > 0)
        {
            if (number1 != NULL)
            {
                *number1 = num;
            }
            return num;
        }
        else
        {
            printf("ERROR: Enter a positive value: ");
            scanf("%lf", &num);
        }
    }
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int x)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("Enter the details for 3 dry food bags of product data for analysis.\n");
    printf("NOTE: A 'serving' is 64g\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", PRODUCT_MAX);
    printf("NOTE: A 'serving' is %dg\n", MAX_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getProductDetails(const int i)
{
    struct CatFoodInfo readfood = {0};
    printf("Cat Food Product #%d\n", i);
    printf("--------------------\n");
    printf("SKU : ");
    do
    {
        getIntPositive(&readfood.sku);
        if (readfood.sku < 1)
            printf("ERROR: Enter a positive value: ");
    } while (readfood.sku < 1);
    printf("PRICE : $");
    do
    {
        getDoublePositive(&readfood.price);
        if (readfood.price <= 0)
            printf("ERROR: Enter a positive value: ");
    } while (readfood.price <= 0);
    printf("WEIGHT (LBS) : ");
    do
    {
        getDoublePositive(&readfood.weight);
        if (readfood.weight <= 0)
            printf("ERROR: Enter a positive value: ");
    } while (readfood.weight <= 0);
    printf("CALORIES/SERV.: ");
    do
    {
        getIntPositive(&readfood.calories);
        if (readfood.calories < 1)
            printf("ERROR: Enter a positive value: ");
    } while (readfood.calories < 1);
    printf("\n");
    return readfood;
}

/***
Create a CatFoodInfo structure variable 'tmp'.
Print the product number passed as a parameter.
Read from the keyboard 4 structure members using getIntPositive() or getDoublePositive().
When you call those functions you may pass NULL as an argument,
that means you don't need the result to be duplicated through the pointer.
Return tmp.
*/

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories,
                        const double *weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

/*** Print 4 structure members using %d and %f format specifiers
First parameter - array of structures,
Second parameter - index in the array.
*/

// 7. Logic entry point
void start()
{
    struct CatFoodInfo catsInfo[PRODUCT_MAX] = {{0}};
    int i;
    openingMessage(PRODUCT_MAX);
    printf("\n");
    for (i = 0; i < PRODUCT_MAX; i++)
    {
        catsInfo[i] = getProductDetails(i + 1);
    }
    displayCatFoodHeader();
    for (i = 0; i < PRODUCT_MAX; i++)
    {
        displayCatFoodData(catsInfo[i].sku, &catsInfo[i].price,
                           catsInfo[i].calories, &catsInfo[i].weight);
    }
    printf("\n");
}