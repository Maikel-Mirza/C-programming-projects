
#include <stdio.h>
int main(void)
{
    int days = 0;
    char ch = 0;
    printf("How many days left? ");
    scanf("%d", &days);
    ch = days > 1 ? 's' : ' ';
    printf("%d day%c left.\n", days, ch);
    return 0;
}