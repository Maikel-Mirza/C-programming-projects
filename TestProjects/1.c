#include <stdio.h>

int main(void)
{
    int numOranges = 0;
    double costOranges = .67;
    double weightBananas = 0.0;
    double costBananas = .59;
    double total = 0.0;

    printf("Enter number of oranges: "); // user enters 2
    scanf("%d", &numOranges);
    printf("Enter weight of bananas: "); // user enters 3.4
    scanf("%lf", &weightBananas);

    total = costBananas * weightBananas + costOranges * numOranges;
    printf("Total is equal to: $%.2lf\n", total);

    return 0;
}