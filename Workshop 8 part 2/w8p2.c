/*
  *****************************************************************************
                            Workshop - #8 (P2)
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
#include <stdbool.h>

// User Libraries
#include "w8p2.h" // where all function prototypes are declared

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
    } while (num < 1);  // loop runs while number entered is negative
    if (number != NULL) 
        *number = num;
    // returns user-entered positive double floating-point value in two ways
    return num;
}

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
                *number1 = num; // assigning value to pointer argument
            }
            return num;
        }
        else
        {
            // error until num is positive non-zero number
            printf("ERROR: Enter a positive value: "); 
            scanf("%lf", &num);
        }
    }
}
// 3. Opening Message printed (include the number of products that need entering)
void openingMessage(const int x)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\
\n", MAX_PRODUCT);
    printf("NOTE: A 'serving' is %dg\n", GRAMS_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getProductDetails(const int i)
{
    struct CatFoodInfo foodDetails = {0};
    printf("Cat Food Product #%d\n", i);
    printf("--------------------\n");
    printf("SKU           : ");
    do
    {
        getIntPositive(&foodDetails.sku);
        if (foodDetails.sku < 1) // cat food sku
            printf("ERROR: Enter a positive value: ");
    } while (foodDetails.sku < 1); // runs until value is positive
    printf("PRICE         : $");
    do
    {
        getDoublePositive(&foodDetails.price);
        if (foodDetails.price <= 0) // cat food price
            printf("ERROR: Enter a positive value: ");
    } while (foodDetails.price <= 0); // runs while price is not greater than 0
    printf("WEIGHT (LBS)  : ");
    do
    {
        getDoublePositive(&foodDetails.weight);
        if (foodDetails.weight <= 0) // cat food weight
            printf("ERROR: Enter a positive value: ");
    } while (foodDetails.weight <= 0); // runs while weight is not greater than 0
    printf("CALORIES/SERV.: ");
    do
    {
        getIntPositive(&foodDetails.calories);
        if (foodDetails.calories < 1) // cat food calories
            printf("ERROR: Enter a positive value: ");
    } while (foodDetails.calories < 1); // runs while calories is less than 1
    printf("\n");
    return foodDetails;
}

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
    // struct members
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories); 
}

// ----------------------------------------------------------------------------
// PART-2
// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *ptrToPounds, double *ptrToKilos)
{
    double result;
    result = *ptrToPounds / LBSKG; // converting lbs to kg
    if (ptrToKilos != NULL)
        *ptrToKilos = result;
    return result;
};
// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *ptrToPounds, int *ptrToGrams)
{
    // not using ptrToKilos because we have int type in parameter 2
    int result;
    result = (*ptrToPounds / LBSKG) * 1000; // deriving kg and multiplying by 1000
    if (ptrToGrams != NULL)
        *ptrToGrams = result;
    return result;
};
// 10. convert lbs: kg and g
void convertLbs(const double *ptrToPounds, double *ptrToKilos, int *ptrToGrams)
{
    double a; // for converting pounds to kilos and grams
    int b;
    a = convertLbsKg(ptrToPounds, ptrToKilos);
    b = convertLbsG(ptrToPounds, ptrToGrams);
    *ptrToKilos = a;
    *ptrToGrams = b;
}
// 11. calculate: servings based on servingSizeGrams
// servingSizeGrams is size in grams |totalGrams is grams for a product
// ptrToNumberOfServings is number of servings
double calculateServings(const int servingSizeGrams, const int totalGrams,
                         double *ptrToNumberOfServings)
{
    double x; // calculating servings based on grams in serving
    x = (double)totalGrams / GRAMS_SERVING;
    if (ptrToNumberOfServings != NULL)
        *ptrToNumberOfServings = x;
    return x;
};
// 12. calculate: cost per serving
double calculateCostPerServing(const double *ptrToProductPrice,
              const double *ptrToNumberOfServings, double *ptrToCostPerServing)
{
    double CPS; // calculating the cost per serving
    CPS = *ptrToProductPrice / *ptrToNumberOfServings;
    if (ptrToCostPerServing != NULL)
        *ptrToCostPerServing = CPS;
    return CPS;
};
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *ptrToProductPrice,
                       const double *ptrToNumberOfCal, double *ptrToCostPerCal)
{
    double CPC; // calculating the cost per cal
    CPC = *ptrToProductPrice / *ptrToNumberOfCal;
    if (ptrToCostPerCal != NULL)
        *ptrToCostPerCal = CPC;
    return CPC;
};
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo info)
{ // reporting data for all cat food items based on ReportData structure,
  // and CatFoodInfo structure
    struct ReportData data;
    data.reportSku = info.sku;
    data.reportPrice = info.price;
    data.calsPerServing = info.calories;
    data.weightPounds = info.weight;
    data.weightKilos = convertLbsKg(&info.weight, &data.weightKilos);
    data.weightGrams = convertLbsG(&info.weight, &data.weightGrams);
    data.totalServings = calculateServings\
    (MAX_PRODUCT, data.weightGrams, &data.totalServings);
    data.costPerServing = calculateCostPerServing\
    (&data.reportPrice, &data.totalServings, &data.costPerServing);
    double cal = data.totalServings * data.calsPerServing;
    data.costOfOneCalory = calculateCostPerCal\
    (&data.reportPrice, &cal, &data.costOfOneCalory);
    return data;
}
// 15. The formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_SERVING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings"
    "  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- --------"
    " ------- -------\n");
}
// 16. The formatted data row in the analysis table
void displayReportData(const struct ReportData data, const double cheapest)
{
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
            data.reportSku, data.reportPrice, data.weightPounds, data.weightKilos,
            data.weightGrams, data.calsPerServing, data.totalServings,
            data.costPerServing, data.costOfOneCalory);
        if (data.costPerServing == cheapest)
        {
                printf(" ***\n"); // displays asterisks on the cheapest option
        }
        else
            printf("\n");
    
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catfoodInfo)
{
    printf("Final Analysis\n"); // provides the most economical option based on data
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%0.2lf\n", catfoodInfo.sku, catfoodInfo.price);
    printf("\n");
    printf("Happy shopping!\n\n");
}
// ----------------------------------------------------------------------------
// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo catsInfo[MAX_PRODUCT + 1]; // array of CatFoodInfo
    int i;                                        // counter used in for loops
    openingMessage(MAX_PRODUCT);
    printf("\n");
    for (i = 0; i < MAX_PRODUCT; i++) // gets product data from user
    {
        // assign values in loop starting from 1st element
        catsInfo[i + 1] = getProductDetails(i + 1); 
    }
    displayCatFoodHeader();           // table header
    for (i = 0; i < MAX_PRODUCT; i++) // will display CatFoodInfo records
    {
        // price and weight are passed by address
        // sku and calories are passed by value
        displayCatFoodData(catsInfo[i + 1].sku, &catsInfo[i + 1].price,        
                           catsInfo[i + 1].calories, &catsInfo[i + 1].weight); 
    }
    printf("\n");
    struct ReportData data[MAX_PRODUCT + 1]; // second structure
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        data[i + 1] = calculateReportData(catsInfo[i + 1]);
    }
    displayReportHeader();                    // the report header
    double cheapest = data[2].costPerServing; // to show result of cheapest option
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        if (data[i + 1].costPerServing < cheapest)
        {
            cheapest = data[i + 1].calsPerServing; // cheapest option available
        }
    }
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        displayReportData(data[i + 1], cheapest);
    }
    printf("\n");
    for (i = 0; i < MAX_PRODUCT; i++)
    {
        if (cheapest == data[2].costPerServing)
        {
            displayFinalAnalysis(catsInfo[2]); // displays the cheapest option
            break;                             
            // to exit the loop after printing result
        }
    }
}