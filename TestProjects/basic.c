#include <stdio.h>

int main()
{
    char likePizza;
    char anotherSlice;
    int pizzaOrNot;
    int slicesOfPizza = 30;
    int i;

    printf("Would you like some pizza? ");
 
     do
    {
        scanf(" %s", &likePizza);
        if (likePizza = 'yes')
        {  
            
            pizzaOrNot = 1;
            
        }
        else if(likePizza = 'no')
        {
            pizzaOrNot = 0;
        }     
    }while (pizzaOrNot == 0);

    return 0;
} 
