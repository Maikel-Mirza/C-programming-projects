#include <stdio.h>

int main()
{
    int number = 13;

    if (number % 2 == 0)
    {
        printf("Even\n");
    }
    else if (number % 2 == 1)
    {
        printf("Odd\n");
    }

    return 0;
}