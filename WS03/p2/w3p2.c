/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Maikel Mirzadegan
	ID     : 032299158
	Email  : mmirzadegan@senecacollege.ca
	Section: NBB
*/
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int year = 0;
	int month = 0;
	int const JAN = 1;
	int const DEC = 12;


	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);
		if (!(year <= MAX_YEAR && year >= MIN_YEAR)) {
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (!(month <= DEC && month >= JAN)) {
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while (!(year <= MAX_YEAR && year >= MIN_YEAR && month<DEC && month>JAN));

	printf("\n*** Log date set! ***\n");



	double morningRating = 0;
	double eveningRating = 0;
	int day = 0;
	double accumulatedMorning = 0;
	double accumulatedEvening = 0;
	double totalO = 0;
	double averageM = 0;
	double averageE = 0;
	double averageO = 0;

	for (day = 1; day <= LOG_DAYS; day++)
	{
		printf("\n");

		if (month == 9) {
			printf("%d-SEP-0%d", year, day);
		}
		if (month == 10) {
			printf("%d-OCT-0%d", year, day);
		}
		if (month == 11) {
			printf("%d-NOV-0%d", year, day);
		}
		if (month == 12) {
			printf("%d-DEC-0%d", year, day);
		}
		if (month == 01) {
			printf("%d-JAN-0%d", year, day);
		}
		if (month == 02) {
			printf("%d-FEB-0%d", year, day);
		}
		if (month == 03) {
			printf("%d-MAR-0%d", year, day);
		}
		if (month == 04) {
			printf("%d-APR-0%d", year, day);
		}
		if (month == 05) {
			printf("%d-MAY-0%d", year, day);
		}
		if (month == 06) {
			printf("%d-JUN-0%d", year, day);
		}
		if (month == 07) {
			printf("%d-JUL-0%d", year, day);
		}
		if (month == 8) {
			printf("%d-AUG-0%d", year, day);

		}
		printf("\n");



		do
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morningRating);

			if ((morningRating >= 0.0 && morningRating <= 5.0)) {
				accumulatedMorning += morningRating;

			}
			else {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}


		} while (!(morningRating >= 0.0 && morningRating <= 5.0));

		do
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &eveningRating);

			if (eveningRating >= 0.0 && eveningRating <= 5.0) {
				accumulatedEvening += eveningRating;
			}
			else {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (!(eveningRating >= 0.0 && eveningRating <= 5.0));
	}

	totalO = accumulatedMorning + accumulatedEvening;
	averageM = accumulatedMorning / 3;
	averageE = accumulatedEvening / 3;
	averageO = (averageM + averageE) / 2;

	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating:  %.3lf\n", accumulatedMorning);
	printf("Evening total rating:  %.3lf\n", accumulatedEvening);
	printf("----------------------------\n");
	printf("Overall total rating:  %.3lf\n\n", totalO);
	printf("Average morning rating :  %.1lf\n", averageM);
	printf("Average evening rating :  %.1lf\n", averageE);
	printf("----------------------------\n");
	printf("Average overall rating :  %.1lf", averageO);



	return 0;
}


