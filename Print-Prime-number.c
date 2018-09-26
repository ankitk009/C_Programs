/* Write a program that prompts user to enter a number N.
a. Print all prime numbers that are less than or equal to N.
b. Display the number of prime numbers that your program has found
*/

#include<stdio.h>
#include<math.h>
int main(void)
{
	int user_input_n, flag = 1, count = 0;
	printf("Enter the number: ");
	scanf("%d", &user_input_n);
	for (int i = 2; i <= user_input_n; i++)
	{
		flag = 0;
		//To check for divisibility between 2 till sqrt(i), if found any number divisible break the count
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				//If found any number increment the flag
				flag++;
				break;
			}
		}
		if (flag == 0 && user_input_n!=1)
		{
			printf("%d\t", i);
			//Counts the number of prime numbers
			count++;
		}
	}
	printf("\nThe total prime numbers are %d", count);
	return 0;
}