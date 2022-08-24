#include <stdio.h>

void main()
{
    char fullname[30];
    char password[30];
    printf("Please enter your full name: ");
    scanf("%[^\n]", fullname);
    printf("Your full name is %s ", fullname);
    printf("\nCreate a password: ");
    scanf("%s", password);
    printf("\nYour password is %s ", password);
}
