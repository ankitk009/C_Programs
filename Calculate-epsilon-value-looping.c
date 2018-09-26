//Write a program that approximates e by computing the value of the above series until the current term becomes less than 𝜀, 
//where 𝜀 is a small (floating point) number entered by the user

#include<stdio.h>
int main (void)
{	
	float epsilon=0;
	float value_e=0,fact =1;
	//For 0 factorial adding value of 1
	value_e+=1;
	printf("Enter a small number ");
	int characters_read =scanf("%f",&epsilon);
	//If user enters characters other than number
	if(characters_read<=0 )
	{	
		printf("Please enter valid number");
		return 0;
	}
	if (epsilon>1)
	{
		printf("Please enter small number" );
		return 0;

	}	
	//For Infinite Looping until breaking condition is reached
	for(int loop_variable=1;;)
	{	
		if ((1/fact)<epsilon)
			break;

		fact=fact*loop_variable;
		value_e=value_e+(1/fact);
		loop_variable++;
	}
printf("The value of e is %f",value_e);
return 0;
}