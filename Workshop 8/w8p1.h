/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
//#include <stdio.h>
#define PRODUCT_MAX 3
#define PRODUCT_MIN 1
#define MAX_GRAMS 64
// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
     int sku;       // product sku
     double price;  // price of product
     int calories;  // calories per serving
     double weight; // product weight in pounds
};

// ----------------------------------------------------------------------------
// function prototypes and explanations

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number);
/*** This function is a do-while loop.
     If the number is negative, the message is printed and the loop continues.
     If the number is positive it is returned twice:
     through the return statement and through the dereferenced pointer.
     Be carefull, if the pointer is NULL, don't dereference it!
*/

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number1);
/*** This function is a do-while loop.
     If the number is negative, the message is printed and the loop continues.
     If the number is positive it is returned twice:
     through return and through the pointer.
     Be carefull, if the pointer is NULL, don't dereference it!
*/

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int x);
/*** Very simple function - check the output in PDF
 */

// 4. Get user input for the details of cat food product
struct CatFoodInfo getProductDetails(const int i);
/***
Create a CatFoodInfo structure variable 'tmp'.
Print the product number passed as a parameter.
Read from the keyboard 4 structure members using getIntPositive() or getDoublePositive().
When you call those functions you may pass NULL as an argument,
that means you don't need the result to be duplicated through the pointer.
Return tmp.
*/

// 5. Display the formatted table header
void displayCatFoodHeader(void);
/*** Very simple function - check the output in PDF
 */

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories,
                        const double *weight);
/*** Print 4 structure members using %d and %f format specifiers
First parameter - array of structures,
Second parameter - index in the array.
*/

// 7. Logic entry point
void start(void);
/*** 1) Create an array of structures.
     2) Print the opening message
     3) In a loop get the product details
     4) Display the cat food header
     5) In a loop display cat food data
*/