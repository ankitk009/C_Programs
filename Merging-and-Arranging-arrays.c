//Take two ascending arrays and merge them into descending order
#include <stdio.h>

int main(void)
{

  int ascendingarray[10], descendingarray[10], len_ascendingarray = 0,
                                               len_descendingarray;
  char inputchar;

  //Read input as integer and character and check for if character
  //is not equal to enterkey which is '\n'
  //Also keep note of input elements taken which is len_array
  do
  {
    scanf("%d%c", &ascendingarray[len_ascendingarray], &inputchar);
    len_ascendingarray++;
    if (len_ascendingarray > 10) //Check if array length not exceeds 10
      break;
  } while (inputchar != '\n');

  do
  {
    scanf("%d%c", &descendingarray[len_descendingarray], &inputchar);
    len_descendingarray++;
    if (len_descendingarray > 10)
      break;
  } while (inputchar != '\n');

  //New merged array length=sum of both araay lengths
  int mergedarray_len = len_ascendingarray + len_descendingarray;
  int mergedarray[mergedarray_len];
  int i = 0, j = len_descendingarray - 1, k = 0;

  //Merge Logic: Take one value from one array and compare it with another
  //If value is smaller, add it to merged array and move to next element
  while (i < len_ascendingarray && j >= 0) //exit when either of array's bounds reached
  {
    if (ascendingarray[i] >= descendingarray[j])
    {
      mergedarray[k++] = descendingarray[j--];
    }
    else
    {
      mergedarray[k++] = ascendingarray[i++];
    }
  }

  //If either of one array bound reached copy the other array values
  while (i < len_ascendingarray)
    mergedarray[k++] = ascendingarray[i++];

  while (j >= 0)
    mergedarray[k++] = descendingarray[j--];

  for (int i = 0; i < mergedarray_len; i++)
    printf("%d ", mergedarray[i]);

  printf("\n");

  return 0;
}
