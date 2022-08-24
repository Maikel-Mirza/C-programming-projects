#include <stdio.h>

int add(void);
int subtract();
int multiply();
int divide();

void main()
{
    int x, y, z, q;
    x = add();
    printf("The sum of two numbers are %d\n", x);
    y = subtract();
    printf("The sum of subtracting two numbers is %d\n", y);
    z = multiply();
    printf("The sum of multiplying two numbers is %d\n", z);
    q = divide(); 
    printf("The sum of dividing two numbers is %d\n", q);
}

int add()
{
    int a, b, sum = 0;
    printf("What are the sum of two numbers? ");
    scanf("%d%d", &a, &b); 
    sum = a + b;
    return sum;
}

int subtract()
{
    int a, b, sum;
    printf("What is the sum of subtracting two numbers? ");
    scanf("%d %d", &a, &b);
    sum = a - b;
   return sum;
    
}

int multiply()
{
    int a, b, sum = 0;
    printf("What is the sum of multiplying two numbers? ");
    scanf("%d %d", &a, &b);
    sum = a * b;
    return sum;
    
}

int divide()
{
    int a, b, sum = 0;
    printf("What is the sum of dividing two numbers? ");
    scanf("%d %d", &a, &b);
    sum = a / b;
    return sum;
}