/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Maikel Mirzadegan
	ID     : 032299158
	Email  : mmirzadegan@senecacollege.ca
	Section: NBB
*/
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int year = 0;
	int month = 0;
	int const JAN = 1;
	int const DEC = 12;


	printf("General Well-being log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf_s("%d %d", &year, &month);
		if (!(year <= MAX_YEAR && year >= MIN_YEAR)) {
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (!(month <= DEC && month >= JAN)) {
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while (!(year <= MAX_YEAR && year >= MIN_YEAR && month<DEC && month>JAN));

	printf("\n*** Log date set! ***\n\n");

	if (month == 9) {
		printf("Log starting date: %d-SEP-01", year);
	}
	if (month == 10) {
		printf("Log starting date: %d-OCT-01", year);
	}
	if (month == 11) {
		printf("Log starting date: %d-NOV-01", year);
	}
	if (month == 12) {
		printf("Log starting date: %d-DEC-01", year);
	}
	if (month == 01) {
		printf("Log starting date: %d-JAN-01", year);
	}
	if (month == 02) {
		printf("Log starting date: %d-FEB-01", year);
	}
	if (month == 03) {
		printf("Log starting date: %d-MAR-01", year);
	}
	if (month == 04) {
		printf("Log starting date: %d-APR-01", year);
	}
	if (month == 05) {
		printf("Log starting date: %d-MAY-01", year);
	}
	if (month == 06) {
		printf("Log starting date: %d-JUN-01", year);
	}
	if (month == 07) {
		printf("Log starting date: %d-JUL-01", year);
	}
	if (month == 8) {
		printf("Log starting date: %d-AUG-01", year);
		
	}
	




	return 0;
}

