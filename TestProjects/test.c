
#include<stdio.h>
#include<string.h>

int main(void)
{
    char str1[] = "Jake";
    char str2[] = "Fred";
    char str3[] = "Mary";
    strcpy(str1, str2);
    if (strcmp(str1, str2))
    {
        printf("Yes\n");
    }
    else if (strcmp(str2, str1))
    {
        printf("YesYes\n");
    }
    else if (strcmp(str3, "Mary"))
    {
        printf("Maybe\n");
    }
    else if (strcmp(str1, str3))
    {
        printf("No\n");
    }
    else
    {
        printf("NoNo\n");
    }
    return 0;
}