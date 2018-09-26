//To print individual words of each digit
#include <stdio.h>
#include <string.h>

int main(void)
{

    int printer = 0;
    char input[20];
    //Take string input from user
    scanf("%s", input);
    
    //Using do-while loop
    char input_orig[20];
    //Copy the original string to preserve that value
    strcpy(input_orig, input);
    for (int i = 0; i < strlen(input); i++)
    {
        printer=input[i] - '0';
        switch (printer)
        {
        case 1:
        {
            printf("one ");
            break;
        }
        case 2:
        {
            printf("two ");
            break;
        }
        case 3:
        {
            printf("three ");
            break;
        }
        case 4:
        {
            printf("four ");
            break;
        }
        case 5:
        {
            printf("five ");
            break;
        }
        case 6:
        {
            printf("six ");
            break;
        }
        case 7:
        {
            printf("seven ");
            break;
        }
        case 8:
        {
            printf("eight ");
            break;
        }
        case 9:
        {
            printf("nine ");
            break;
        }
        case 0:
        {
            printf("zero ");
            break;
        }
        default:
            printf("Invalid ");
        }
    }
    printf("\n");
    return 0;
}
