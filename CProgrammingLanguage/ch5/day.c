#include <stdio.h>

// ex. 5-9: re-written to use an array of pointers instead of indexing in functions

static char daytable[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// returns the day of year from year, month and day
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char * p;

    if (year >= 0 && year <= 3000 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
    {
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // sets leap to 0 if not a leap year; 1 if it is a leap year

        // set 'p' to point at first month in correct row
        p = &daytable[leap][0];

        for (i = 0; i < month - 1; i++)
        {
            //day += daytable[leap][i];
            day += *p;
            p++;
        }
        return day;
    }
    else    // error
        return -1;
}

// set month and day from year and the day count
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char * p;

    if (year >= 0 && year <= 3000 && yearday > 0 && yearday <= 366)
    {
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

        p = &daytable[leap][0];

        for (i = 0; yearday > daytable[leap][i]; i++)
        {
            //yearday -= daytable[leap][i];
            yearday -= *p;
            p++;
        }
        *pmonth = i + 1;
        *pday = yearday;
    }
    else // error
    {
        *pmonth = -1;
        *pday = -1;
    }
}

int main(int argc, char ** argv)
{
    int daycount = 0;
    int day = 0;
    int month = 0;
    int year = 0;


    if (argc >= 4)
    {
        day = atoi(argv[2]);  
        month = atoi(argv[1]);
        year = atoi(argv[3]); 

        daycount = day_of_year(year, month, day);
        printf("The number of days in %02d/%02d/%d = %d\n", month, day, year, daycount);
    }
    else if (argc > 2 && argc < 4)
    {
        year = atoi(argv[1]);
        daycount = atoi(argv[2]);

        month_day(year, daycount, &month, &day);

        printf("The %dth day of %d corresponds to %02d/%02d/%d\n", daycount, year, month, day, year);
    }
    else
        printf("ERROR: incorrect number of arguments.\nEnter month day year as integers to get the day of the year\nOr enter year dayofyear to get the date\n");

}
