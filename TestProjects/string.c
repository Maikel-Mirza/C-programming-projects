#include <stdio.h>
#include <stdlib.h>

void main()
{
    char buffer[80];
    int an_int;
    double a_double;

    printf("Type a string:");
    gets(buffer);
    printf("Thats what you typed %s\n", buffer);
    puts(buffer);

    printf("Type an integer:");
    gets(buffer);
    an_int = atoi(buffer);
    printf("Thats what you typed %i\n", an_int);
   

    printf("Type a double:");
    gets(buffer);
    a_double = atof(buffer);
    printf("Thats what you typed %f\n", a_double);
  puts(buffer);
}