//To find digit's of number entered
#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(void)
{

    int input = 0, holder = 0, unitsdigit = 0;

    scanf("%d", &input);
//    printf("Digit by digit from unit's place:");

    holder = input; //To keep input from changing
    //Using do-while loop to iterate over single digit

    do
    {
        unitsdigit = holder % 10;  //Retrive digit at unit place
        printf("%d ", unitsdigit); //Print the last digit
        holder = holder / 10;   //Remove the digit at unit place
    } while (holder != 0);      //keep on repeating till reached 0

    printf("\n");
    return 0;
}
