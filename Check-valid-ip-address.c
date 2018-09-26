/*
Write a program that asks the user for an IP address in dot-decimal notation, and checks to see whether it is a valid IP address, 
the user can enter any character, and your code is supposed to do all the checks:
Enter IP address: 129.1.2.15 It is valid
Enter IP address: 128.1.350.15 It is invalid
*/

#include<stdio.h>
int main (void)
{
	int ip_1=0,ip_2=0,ip_3=0,ip_4=0;
	printf("Enter IP address:");
	//To check the value of integer character read by scanf
	int read_count=scanf("%d.%d.%d.%d", &ip_1, &ip_2, &ip_3, &ip_4);
	if(read_count==0 || ip_1<0 || ip_1>255 || ip_2<0 || ip_2>255 || ip_3<0 || ip_3>255 || ip_4<0 || ip_4>255)
	printf("It is invalid");
	else
	printf("It is valid");
	return 0;
}	