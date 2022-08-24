#include<stdio.h>

void prime(int);

void main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    prime(a);
}

void prime(int n)
{
    int i;
    int c = 0;
    for (i=1; i<=n;i++)
    {
        if(n%i==0)
        c=c+1;
    }
    if (c==2)
    printf ("The number is PRIME");
    else
    printf ("The number is COMPOSITE");
}
