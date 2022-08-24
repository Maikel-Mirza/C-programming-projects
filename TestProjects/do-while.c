#include <stdio.h>
int main(void)
{
    /*********************************************************************************/
    /* The do loop differs from the while loop in that the test to see if the loop   */
    /* should be executed is done at the end of the loop, not at the beginning. As a */
    /* result, the do loop must be executed at least once.                           */
    /*                                                                               */
    /* TODO: The loop below finds the average of a series of values until a negative */
    /* number is found, indicating the end of the numbers. Complete the code to make */
    /* it function correctly.                                                        */
    /*********************************************************************************/
    int n = -1, sum = 0, count = 0;
    double average;
    do
    {
        printf("Enter an integer (negative to stop): ");
        scanf("%d", &n);
        if (n >= 0)
        {
            sum = sum + n;
            count++;
            average = (double)(sum / count);
            /* add the value we just read onto the sum and add one onto count */
        }
    } while (!(n < 0));

    printf("The average of the numbers is %.2lf\n", average);

    return 0;
}
