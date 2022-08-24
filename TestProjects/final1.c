#include <stdio.h>
#include <string.h>

// Should be able to accommodate varying data file sizes up to 250 records
#define MAX_RECORDS 250

// User defined structures
struct Date
{
    int year;
    int month;
};
struct Location
{
    int regionCode;
    char name[20];
};
struct WeatherRecord
{
    struct Date date;
    double precipAmt;
    char unit;
    struct Location location;
};

// Function prototypes
int importWeatherDataFile(FILE *fp, struct WeatherRecord *data, int max);
void viewAll(struct WeatherRecord *data, int recs);
void viewByRegion(struct WeatherRecord *data, int recs);
void viewByMonth(struct WeatherRecord *data, int recs);
void viewByLocation(struct WeatherRecord *data, int recs);
void pause(void);

// start of main program
int main()
{
    char selection;
    FILE *fp;
    struct WeatherRecord data[MAX_RECORDS];
    // open the Weatherdata.txt file
    fp = fopen("Weatherdata.txt", "r");
    // call the provided importWeatherDataFile() to read the weather data
    int recs = importWeatherDataFile(fp, data, MAX_RECORDS);
    // continue looping until user enters 0
    do
    {
        printf("=======================================================\n"
               "        Ontario Weather Analysis Service\n"
               "                 Year: 2021\n"
               "=======================================================\n"
               "1. View all data\n"
               "2. View by region (sorted DESCENDING by precip.)\n"
               "3. View by month (sorted ASCENDING by precip.)\n"
               "4. View by location name (sorted DESCENDING by precip.)\n"
               "-------------------------------------------------------\n"
               "0. Exit\n"
               "-------------------------------------------------------\n"
               "Selection: ");
        scanf(" %c%*c", &selection);
        putchar('\n');
        switch (selection)
        {
        case '0':
            printf("Application Terminated!\n");
            break;
        case '1':
            viewAll(data, recs);
            break;
        case '2':
            viewByRegion(data, recs);
            break;
        case '3':
            viewByMonth(data, recs);
            break;
        case '4':
            viewByLocation(data, recs);
            break;
        default:
            printf("Invalid option selected. Please choose again!\n");
            break;
        }
        putchar('\n');
    } while (selection != '0');
    return 0;
}

// read the weather data from the file
int importWeatherDataFile(FILE *fp, struct WeatherRecord *data, int max)
{
    int recs = 0;

    if (fp != NULL)
    {
        while (recs < max &&

               fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",
                      &data[recs].date.year, &data[recs].date.month,
                      &data[recs].precipAmt, &data[recs].unit,
                      &data[recs].location.regionCode,
                      data[recs].location.name) == 6)
        {
            recs++;
        }
    }
    return recs;
}

// Wait for user to input the "enter" key to continue
void pause(void)
{
    printf("\n< Press [ENTER] key to continue >\n");
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// display all the records in the weather data
void viewAll(struct WeatherRecord *data, int recs)
{
    printf("Year Month Precip.Amt Unit Region Name\n"
           "---- ----- ---------- ---- ------ ---------------\n");
    int i;
    for (i = 0; i < recs; i++)
    {
        if (i % 15 == 0 && i > 0)
            pause();
        printf("%4d %4d %10.1f %4c %6d %s\n",
               data[i].date.year, data[i].date.month,
               data[i].precipAmt, data[i].unit,
               data[i].location.regionCode,
               data[i].location.name);
    }
}

// display the data by region (descending order by precip.)
void viewByRegion(struct WeatherRecord *data, int recs)
{
    int region[4] = {10, 20, 30, 40};
    double precip[4] = {0};
    int i;
    // get the total data for each region
    for (i = 0; i < recs; i++)
    {
        if (data[i].location.regionCode == 10)
        {
            if (data[i].unit == 'c')
                precip[0] = data[i].precipAmt * 10 + precip[0];
            else if (data[i].unit == 'm')
                precip[0] = data[i].precipAmt + precip[0];
        }
        if (data[i].location.regionCode == 20)
        {
            if (data[i].unit == 'c')
                precip[1] = data[i].precipAmt * 10 + precip[1];
            else if (data[i].unit == 'm')
                precip[1] = data[i].precipAmt + precip[1];
        }
        if (data[i].location.regionCode == 30)
        {
            if (data[i].unit == 'c')
                precip[2] = data[i].precipAmt * 10 + precip[2];
            else if (data[i].unit == 'm')
                precip[2] = data[i].precipAmt + precip[2];
        }
        if (data[i].location.regionCode == 40)
        {
            if (data[i].unit == 'c')
                precip[3] = data[i].precipAmt * 10 + precip[3];
            else if (data[i].unit == 'm')
                precip[3] = data[i].precipAmt + precip[3];
        }
    }
    // Sort the data
    int j, n = 4;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (precip[j] < precip[j + 1])
            {
                int temp = precip[j];
                precip[j] = precip[j + 1];
                precip[j + 1] = temp;
                temp = region[j];
                region[j] = region[j + 1];
                region[j + 1] = temp;
            }
        }
    }
    double total = 0;
    printf("Region Name     Precip(mm)\n"
           "------ -------- ----------\n");
    for (i = 0; i < n; i++)
    {
        total = precip[i] + total;
        if (region[i] == 10)
            printf("%6d %-8s %10.0lf\n", region[i], "Western", precip[i]);
        if (region[i] == 20)
            printf("%6d %-8s %10.0lf\n", region[i], "Northern", precip[i]);
        if (region[i] == 30)
            printf("%6d %-8s %10.0lf\n", region[i], "Eastern", precip[i]);
        if (region[i] == 40)
            printf("%6d %-8s %10.0lf\n", region[i], "Central", precip[i]);
    }
    printf("------ -------- ----------\n");
    printf("         Total: %10.0lf\n", total);
    printf("       Average: %10.2lf\n", total / n);
}

// display the data by month (ascending order by precip.)
void viewByMonth(struct WeatherRecord *data, int recs)
{
    int month[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    double precip[12] = {0};
    int i;
    // get the total data for each month
    for (i = 0; i < recs; i++)
    {

        if (data[i].unit == 'c')
            precip[data[i].date.month - 1] = data[i].precipAmt * 10 + precip[data[i].date.month - 1];
        else if (data[i].unit == 'm')
            precip[data[i].date.month - 1] = data[i].precipAmt + precip[data[i].date.month - 1];
    }
    // Sort the data
    int j, n = 12;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (precip[j] > precip[j + 1])
            {
                int temp = precip[j];
                precip[j] = precip[j + 1];
                precip[j + 1] = temp;
                temp = month[j];
                month[j] = month[j + 1];
                month[j + 1] = temp;
            }
        }
    }
    double total = 0;
    printf("Month     Precip(mm)\n"
           "--------- ----------\n");
    for (i = 0; i < n; i++)
    {
        total = precip[i] + total;
        if (month[i] == 1)
            printf("%-9s %10.0lf\n", "January", precip[i]);
        if (month[i] == 2)
            printf("%-9s %10.0lf\n", "Februay", precip[i]);
        if (month[i] == 3)
            printf("%-9s %10.0lf\n", "March", precip[i]);
        if (month[i] == 4)
            printf("%-9s %10.0lf\n", "April", precip[i]);
        if (month[i] == 5)
            printf("%-9s %10.0lf\n", "May", precip[i]);
        if (month[i] == 6)
            printf("%-9s %10.0lf\n", "June", precip[i]);
        if (month[i] == 7)
            printf("%-9s %10.0lf\n", "July", precip[i]);
        if (month[i] == 8)
            printf("%-9s %10.0lf\n", "August", precip[i]);
        if (month[i] == 9)
            printf("%-9s %10.0lf\n", "September", precip[i]);
        if (month[i] == 10)
            printf("%-9s %10.0lf\n", "October", precip[i]);
        if (month[i] == 11)
            printf("%-9s %10.0lf\n", "November", precip[i]);
        if (month[i] == 12)
            printf("%-9s %10.0lf\n", "December", precip[i]);
    }
    printf("--------- ----------\n");
    printf("   Total: %10.0lf\n", total);
    printf(" Average: %10.2lf\n", total / n);
}

// display the data by location (descending order by precip.)
void viewByLocation(struct WeatherRecord *data, int recs)
{
    char location[8][20] = {"Chatham-Kent",
                            "Halton",
                            "Renfrew",
                            "Kenora",
                            "Simcoe",
                            "Essex",
                            "Ottawa",
                            "Thunder Bay"};
    double precip[8] = {0};
    int i;
    // get the total data for each location
    for (i = 0; i < recs; i++)
    {
        if (strcmp(data[i].location.name, "Chatham-Kent") == 0)
        {
            if (data[i].unit == 'c')
                precip[0] = data[i].precipAmt * 10 + precip[0];
            else if (data[i].unit == 'm')
                precip[0] = data[i].precipAmt + precip[0];
        }
        if (strcmp(data[i].location.name, "Halton") == 0)
        {
            if (data[i].unit == 'c')
                precip[1] = data[i].precipAmt * 10 + precip[1];
            else if (data[i].unit == 'm')
                precip[1] = data[i].precipAmt + precip[1];
        }
        if (strcmp(data[i].location.name, "Renfrew") == 0)
        {
            if (data[i].unit == 'c')
                precip[2] = data[i].precipAmt * 10 + precip[2];
            else if (data[i].unit == 'm')
                precip[2] = data[i].precipAmt + precip[2];
        }
        if (strcmp(data[i].location.name, "Kenora") == 0)
        {
            if (data[i].unit == 'c')
                precip[3] = data[i].precipAmt * 10 + precip[3];
            else if (data[i].unit == 'm')
                precip[3] = data[i].precipAmt + precip[3];
        }
        if (strcmp(data[i].location.name, "Simcoe") == 0)
        {
            if (data[i].unit == 'c')
                precip[4] = data[i].precipAmt * 10 + precip[4];
            else if (data[i].unit == 'm')
                precip[4] = data[i].precipAmt + precip[4];
        }
        if (strcmp(data[i].location.name, "Essex") == 0)
        {
            if (data[i].unit == 'c')
                precip[5] = data[i].precipAmt * 10 + precip[5];
            else if (data[i].unit == 'm')
                precip[5] = data[i].precipAmt + precip[5];
        }
        if (strcmp(data[i].location.name, "Ottawa") == 0)
        {
            if (data[i].unit == 'c')
                precip[6] = data[i].precipAmt * 10 + precip[6];
            else if (data[i].unit == 'm')
                precip[6] = data[i].precipAmt + precip[6];
        }
        if (strcmp(data[i].location.name, "Thunder Bay") == 0)
        {
            if (data[i].unit == 'c')
                precip[7] = data[i].precipAmt * 10 + precip[7];
            else if (data[i].unit == 'm')
                precip[7] = data[i].precipAmt + precip[7];
        }
    }
    // Sort the data
    int j, n = 8;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (precip[j] < precip[j + 1])
            {
                int temp = precip[j];
                precip[j] = precip[j + 1];
                precip[j + 1] = temp;
                char stemp[20];
                strcpy(stemp, location[j]);
                strcpy(location[j], location[j + 1]);
                strcpy(location[j + 1], stemp);
            }
        }
    }
    double total = 0;
    printf("Location        Precip(mm)\n"
           "--------------- ----------\n");
    for (i = 0; i < n; i++)
    {
        total = precip[i] + total;
        printf("%15s %10.0lf\n", location[i], precip[i]);
    }
    printf("--------------- ----------\n");
    printf("         Total: %10.0lf\n", total);
    printf("       Average: %10.2lf\n", total / n);
}