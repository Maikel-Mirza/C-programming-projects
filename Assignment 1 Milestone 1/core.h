#ifndef __CORE__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Clear the standard input buffer
void clearInputBuffer();
// Wait for user to input the "enter" key to continue
void suspend();

// my function prototypes
int		inputInt();

int		inputIntPositive(void);

int		inputIntRange(int low, int high);

char	inputCharOption(const char* validChars);

void	inputCString(char* result, int minChars, int maxChars);

void	displayFormattedPhone(char* validatedString);

#endif // !__CORE__H