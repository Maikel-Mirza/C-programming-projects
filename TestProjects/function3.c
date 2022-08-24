#include <stdio.h>

void function_one();

void main(){

    function_one();

}


void function_one(){
    int flag1=0;
    char beverageChosen[80];
    int counter= 5;
    int i;
    char read[80];
do
{

    for(i = 0; i < counter; i++)
    {
        printf("Hi how are you doing?\n");
        gets(read);
        puts(read);
        printf("What would you like\nwe have coffee, tea, juice and water\n");
        scanf("%s", beverageChosen);
        if (beverageChosen == 'tea')
        {
          printf("Sorry, please chose one of the options available\n");
        }
        else{
            printf("That sounds wonderful, comming right up!\n");
            flag1 = 1;
        }
        
    }    
} while (flag1 == 0);

    

}