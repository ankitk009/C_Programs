/*
Write a program that prompts the user to enter a series of dates and then indicate which date comes earlier on the calendar. The user will enter 0/0/0
 to indicate that no more dates will be entered:
 Enter a date (mm/dd/yy): 3/6/08 
 Enter a date (mm/dd/yy): 5/17/07 
 Enter a date (mm/dd/yy): 6/3/07 
 Enter a date (mm/dd/yy): 0/0/0 
 5/17/07 is the earliest date
*/
#include<stdio.h>
int main(void)
{
	int month = -1, day = -1, year = -1, n;
	//Temporary variables are created
	int month1 = 99, day1 = 99, year1 = 99;
	//For infinite looping
	while (1 == 1)
	{
		printf("\nEnter a date(mm/dd/yy):");
		n = scanf("%d/%d/%d", &month, &day, &year);
		//Month and Day check
		if ((month > 12) || (day > 31) || (day<0) || (month<0))
			printf("\nEnter valid date");
		//If day,month and year are 0 break the loop
		if (year == 0 && month == 0 && day == 0)
			break;
		else if ((month == 0 && day == 0) || (month == 0 && year == 0) || (day == 0 || year == 0) || (year == 0) || (month == 0) || (day == 0))
		{
			printf("\nEnter valid date");
		}
		else
		{
			//First Year Comparision is done, if year are same ,comparision of months and if months are equal ,days are compared
			if (year < year1)
			{
				year1 = year;
				month1 = month;
				day1 = day;
			}
			if (year == year1)
			{
				if (month < month1)
				{
					month1= month;
				}
				if (month == month1)
				{
					day1 = day < day1 ? day : day1;
				}
			}
		}

	}


	printf("\n%.2d/%.2d/%.2d is the earliest date", month1, day1, year1);
}