#include <stdio.h>



int colourMatch (char colour, char eyeColour)
{
    int i, correct;

    for (i = 0; i < 5 && correct == 0; i++)
    {
        correct = (colour == eyeColour);
    }

    return correct;
}


int main()
{
    char colour, eyeColour;
    int answer, correct;

    printf("Whats your favourite colour?");
    scanf(" %s", &colour);
    printf("Whats your eye colour?");
    scanf(" %s", &eyeColour);
    //printf("Your favourite colour is %s", &eyeColour);

    answer = colourMatch(colour, eyeColour);
    if(colourMatch(correct == 0))
    {
        printf(" your favourite colour %c does not match eye colour %c\n", colour, eyeColour);
    }
    
}