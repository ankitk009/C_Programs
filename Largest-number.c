//To calculate largest numbers using ternary operator
#include <stdio.h>

int main(void)
{

    int input1 = 0, input2 = 0, input3 = 0;
    int middle = 0, highest = 0, lowest = 0;

    scanf("%d%d%d", &input1, &input2, &input3);

    //To find highest number, used ternary operator
    highest = input1 > input2 ? (input1 > input3 ? input1 : input3) : (input2 > input3 ? input2 : input3);
//    printf("%d\n",highest);

    //To find lowest number
    lowest = input1 < input2 ? (input1 < input3 ? input1 : input3) : (input2 < input3 ? input2 : input3);
//    printf("%d\n",lowest);

    //To find middle element, to check which is highest,lowest and remaining would be middle
    middle = (input1 == lowest) ? (input3 == highest ? input2 : input3) : (input1 == highest ? (input3 == lowest ? input2 : input3) : input1);
//    printf("%d\n",middle);

    printf("%d %d %d\n", lowest, middle, highest);

    return 0;
}
