#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 0;
    while (i < 10)
    {
        sum = sum + i;
        i++;
        printf("%d\n", i);
    }
    printf("The sum is %d\n", sum);

    return 0;
}