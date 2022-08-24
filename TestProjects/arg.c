#include<stdio.h>

void addTwo(int* param1, int* param2)
{
    *param1 -= 2;
    *param2 += 3;
    return;
}

int main(void)
{
    int arg1 = 5, arg2 = 7;
    addTwo(&arg1, &arg2);
    printf("arg1 = %d and arg2 = %d\n", arg1, arg2);
    return 0;
}