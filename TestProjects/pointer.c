#include <stdio.h>

int main()
{
    int leavesOnTree = 10;
    int *p = &leavesOnTree;

    printf("There are %d leaves on a tree\n", leavesOnTree);
    *p = 20;
    printf("There are %d leaves on a tree\n", *p);

    do
    {
        printf("How much do you make in an hour?");
        scanf("%d", &*p);
        printf("\nYou make %d an hour!\n", *p);
        if(*p > 50 || *p < 0)
        {
            printf("That cant be right!...\n");
        }

    } while (*p > 50 || *p < 0);
    
    return 0;
}