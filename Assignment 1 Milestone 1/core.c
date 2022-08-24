/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  :    Maikel Mirzadegan
Student ID#:    032299158
Email      :    mmirzadegan@senecacollege.ca
Section    :    NPP

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "core.h" // function prototype declarations

void clearInputBuffer(void) // Clear the standard input buffer
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing 
    }
}

void suspend(void) // Wait for user to input the "enter" key to continue
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
// this function returns an integer value and receives no arguments
int inputInt(void) // tester 1
{
    int intValue = 0;
    char newLine = 'n';
    do
    {
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            // ensure the input is a whole number
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (newLine != '\n');
    return intValue;
}
// this function returns an integer value and receives two arguments
int inputIntPositive(void) // tester 2
{
    int intValue = 0;
    char newLine = 'n';
    do
    { // input must be greater than zero
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("ERROR! Value must be > 0: "); 
        }
        else if (intValue <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (newLine != '\n' || intValue <= 0);
    return intValue;
}
// this function returns an integer value and receives two arguments
int inputIntRange(int low, int high) // tester 3 and 4
{
    int intValue = 0;
    char newLine;
    do
    { // input must be greater than zero
        newLine = 'n';
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: "); 
        }
        else if (intValue < low || intValue > high)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", low, high);
        }
    } while (newLine != '\n' || intValue < low || intValue > high);
    return intValue;
}
/* this function receives a single character value from the keyboardand validates
   that the entered character matches any of the characters in the received C
   string argument
*/
char inputCharOption(const char* validChars) // tester 5
{
    char chr = 'c';
    char newLine = 'n';
    int i = 0;
    int flag = 1;
    int length = strlen(validChars);
    do
    {
        scanf("%c%c", &chr, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
        }
        else
        {
            for (i = 0; i < length; i++)
            {
                if (validChars[i] == chr)
                    flag = 0;
            }
        }
        if (flag == 1)
        { // error if character doesn't match expected results
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    } while (flag);
    return chr;
}
/*  this function obtains user input for a C string value with a length
    and validates that the entered number of characters is within the specified range
*/
void inputCString(char* result, int minChars, int maxChars) // tester 6, 7 and 8
{
    int size = 0;
    int validString = 0; // flag for valid string
    char string[100] = { '\0' };

    do {
        size = 0;
        scanf(" %[^\n]", string);
        while (string[size++] != '\0');
        size--;

        if (size >= minChars && size <= maxChars) {
            strcpy(result, string);
            clearInputBuffer();
            validString = 1;
            // valid string, exit loop
        }
        else if (minChars == maxChars) {
            if (size != minChars)
            {   // error message if string is not the right length
                printf("ERROR: String length must be exactly %d chars: ", maxChars);
                clearInputBuffer();
            }
        }
        else
        {
            if (size > maxChars) {
                printf("ERROR: String length must be no more than% d chars: ", maxChars);
                clearInputBuffer();
            }
            else if (size < minChars)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChars, maxChars);
                clearInputBuffer();
            }
        }
    } while (!validString);

}
// This function calculates the String Length and is used in the next function
int string(const char phone[]) {
    int i;
    for (i = 0; phone[i] != 0; i++);
    return i;
}


void displayFormattedPhone(char* validatedString) // tester 9
    {
        // if validatedString is NULL, display the string and exit the function
        if (validatedString == NULL) 
        {
            printf("(___)___-____");
            return; 
        }
        int i = 0;
        int counter = 0;
        int length = string(validatedString);
        for (i = 0; i < length; i++)
        {
            if (validatedString[i] >= '0' && validatedString[i] <= '9')
            {
                counter++;
            }
        }
        /* string length is not equal to 10 or if characters are not digits,
           display the required string and exit
        */
        if (length != 10 || length != counter)
        {
            printf("(___)___-____");
        }
      
        else // displays the expected formated phone number
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", // 10 digits in a phone number
                validatedString[0],
                validatedString[1],
                validatedString[2],
                validatedString[3],
                validatedString[4],
                validatedString[5],
                validatedString[6],
                validatedString[7],
                validatedString[8],
                validatedString[9]);
        }
    }