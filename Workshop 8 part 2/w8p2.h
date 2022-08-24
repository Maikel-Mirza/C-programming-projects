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
#define MAX_PRODUCT 3    // max products to analyze
#define MIN_PRODUCT 1    // min products to analyze
#define GRAMS_SERVING 64 // grams in a suggested serving size
#define LBSKG 2.20462    // num of pounds in a kilo
// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
  int sku;       // product sku
  double price;  // price of product
  int calories;  // calories per serving
  double weight; // product weight in pounds
};

struct ReportData
{
  int reportSku;          // product sku
  double reportPrice;     // price of product
  int calsPerServing;     // calories per serving
  double weightPounds;    // product weight in pounds
  double weightKilos;     // product weight in kilos
  int weightGrams;        // product weight in grams
  double totalServings;   // the total num of servings
  double costPerServing;  // cost of a serving
  double costOfOneCalory; // the cost of calories per serving
};
// ----------------------------------------------------------------------------
// function prototypes and explanations

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number1);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int x);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getProductDetails(const int i);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories,
                        const double *weight);
// ----------------------------------------------------------------------------
// PART-2
// 8. convert lbs: kg
double convertLbsKg(const double *ptrToPounds, double *ptrToKilos);
// 9. convert lbs: g
int convertLbsG(const double *ptrToPounds, int *ptrToGrams);
// 10. convert lbs: kg / g
void convertLbs(const double *ptrToPounds, double *ptrToKilos, int *ptrToGrams);
// 11. calculate: servings based on gPerServ
// servingSizeGrams is size in grams |totalGrams is grams for a product 
// ptrToNumberOfServings is number of servings
double calculateServings(const int servingSizeGrams, const int totalGrams,
                         double *ptrToNumberOfServings);
// 12. calculate: cost per serving
// ptrToProductPrice-product price | ptrToNumberOfServings-total number of servings
// ptrToCostPerServing - cost per servings
double calcuateCostPerServing(const double *ptrToProductPrice,
           const double *ptrToNumberOfServings, double *ptrToCostPerServing);
// 13. calculate: cost per calorie
// ptrToProductPrice-product price | ptrToNumberOfCal-total number of cals
// ptrToCostPerCal - cost per calorie
double calculateCostPerCal(const double *ptrToProductPrice,
                   const double *ptrToNumberOfCal, double *ptrToCostPerCal);
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo info);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);
// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const double cheapest);
// 17. Display the findings (cheapest) cheapest = cheapest option
void displayFinalAnalysis(const struct CatFoodInfo catfoodInfo);
// ----------------------------------------------------------------------------
// 7. Logic entry point
void start(void);