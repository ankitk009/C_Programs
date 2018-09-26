/**********************************************************************************************************************************/
/* 

Write a program that receives a string as command lines argument and determines whether it represents a valid MAC address or not. Note that the user might enter anything as the input, 
and the program must handle all situations. Make sure that your code is robust and reliable in identifying both invalid and valid inputs.
If the name of your .exe file is CHECKMAC, below are sample inputs and outputs:
CHECKMAC 01:23:45:67:89:ab test
ERROR: Please provide only one string
CHECKMAC 01:23:45:67:89:Z2
ERROR: ‘Z’ is not a valid character in MAC address
CHECKMAC 01a:23:45:67:89:ab
ERROR: ‘o1a’ is not valid in MAC address
CHECKMAC 01:23:45:67:89
ERROR: Not a valid MAC address
CHECKMAC 01:23:45:67:89:ab:74
ERROR: Length is too long for a MAC address
CHECKMAC 01:23:45:67:89:ab
The MAC address is valid

*/
/**********************************************************************************************************************************/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[])
{
    void checkMac(char []);
    //If no arguments are provided
    if (argc==1)
    {
        printf("Enter command line arguments");
        return 0;
    }
    //If more than one MAC addresss provided 
    if (argc > 2)
    {
        printf("Please provide only one string");
        return 0;
    }
    
    checkMac(argv[1]);
        return 0;
}
void checkMac(char input_argv[])
{
	int count = 0;
	char input[strlen(input_argv)];
    //Copy the input string into other temporary string
    strcpy(input, input_argv);  

    //If incorrect number of colons are entered
    for (int i=0;i<strlen(input);i++)
        if (input[i] == ':')
                count++;
    if (count != 5)
    {
        printf("Not a valid MAC address");
        return;
    }

    //Split the string by ':' into tokens 
	char* tokens_argv[strlen(input_argv)];
    size_t n = 0;
    for (char* p = strtok(input_argv, ":"); p; p = strtok(NULL, ":"))
    {
        if (n >50)
            break;
        tokens_argv[n++] = p;
    }
    //If more than 2 characters are entered
    for (size_t i = 0; i != n; i++)
    {
        if (strlen(tokens_argv[i]) > 2)
        {
            printf("'%s' is not valid in MAC address", tokens_argv[i]);
            return;
        }
        //If characters other than hexadecimal are entered
        for (int j = 0; j < strlen(tokens_argv[i]); j++)
        {
            if (!isxdigit(tokens_argv[i][j]))
            {
                printf("'%c' is not valid character in MAC address", tokens_argv[i][j]);
                return;
            }
            
        }

    }
//For incorrect length of MAC address
    if (strlen(input) < 17)
    {
        printf("Not a valid MAC address");
        return;
    }
    if (strlen(input) > 17)
    {
        printf("Length is too long for a MAC address");
        return;
    }

    printf("The MAC address is valid");
}