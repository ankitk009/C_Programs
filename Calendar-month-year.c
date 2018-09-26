// Displays the calendar of specified month and year
#include <stdio.h>
#include <math.h>

int main(void)
{

    int dayofweeknum = 0, month, year, sum = 0, weekday = 0;  //Month and year are taken from user

    //To calculate the weekday of 1st January
    //0 - Sunday, 1 - Monday,...... 6 - Saturday
    //Siplified version of Zeller's congruence theorem
    dayofweeknum = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

    //Array of number of days per month
    int daysofmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //To check if its a leap year, then add 29 days for February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysofmonth[1] = 29;

    //For Calendar heading based on Month
    switch (month)
    {
    case (1):
        printf("    %s %d\n", "January", year);
        break;
    case (2):
        printf("    %s %d\n", "Febuary", year);
        break;
    case (3):
        printf("   %s %d\n", "March", year);
        break;
    case (4):
        printf("   %s %d\n", "April", year);
        break;
    case (5):
        printf("   %s %d\n", "May", year);
        break;
    case (6):
        printf("   %s %d\n", "June", year);
        break;
    case (7):
        printf("   %s %d\n", "July", year);
        break;
    case (8):
        printf("   %s %d\n", "August", year);
        break;
    case (9):
        printf("   %s %d\n", "September", year);
        break;
    case (10):
        printf("   %s %d\n", "October", year);
        break;
    case (11):
        printf("   %s %d\n", "November", year);
        break;
    case (12):
        printf("   %s %d\n", "December", year);
        break;
    }

    //To calculate number of days offset for given month
    //For eg. for month of August, days passed=Total days of January+February+March ...
    for (int i = 0; i < month; i++)
    {
        if (i < 1)
            sum = 0;
        else
            sum = sum + daysofmonth[i];
    }

    //Calculate starting weekday for given month
    weekday = (sum + dayofweeknum) % 7;

    //Print calendar heading
    printf(" S  M Tu  W Th  F  S\n");

    //Start the calendar from that specified day, else insert spaces before that
    for (int i = 0; i < weekday; i++)
        printf("%2s ", " ");

    //Calendar printing logic
    int dates = 1;                  //extra variables which is printed and iterates till that days of month
    for (int i = weekday + 1;; i++) //Keeps on printing till break encountered
    {
        if (i < 7)
            printf("%2d ", dates); //To print week day -1 
        if (i == 7)                //For new week print on new line
        {
            printf("%2d", dates); //Print week day
            printf("\n");
            i = 0;
        }
        if (dates == daysofmonth[month - 1] - 1)
        { //print till number of days
            break;
        }
        dates++;
    }
    printf("%2d", ++dates);
    printf("\n");
    printf("\n");
    

    return 0;
}
