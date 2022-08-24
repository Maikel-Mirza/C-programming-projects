#include "hoop.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char planets[80];
    printf("How many planets are there in our solar system? ");
    scanf("%[^\n]", planets);
    puts(planets);
}