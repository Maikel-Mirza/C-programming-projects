#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SZ 3

int main(void)
{
    int i, one = 0, two = 0, total = 0;
    printf("Enter two whole numbers separated by a space: "); // user enters 56 2
    total = scanf("%d %d", &one, &two);
    for (i = 0; i < SZ; i++)

    {
        if (i % two)

        {
            total = two + one / total;
        }
        else

        {
            total += one * two;
        }
    }
    printf("total is equal to %d\n", total);
    return 0;
}

// The above code is broken, it should output - "total is equal to 114" but it outputs - - - - - - - - - - - - - - - - - - - - - -"total is equal to -334"