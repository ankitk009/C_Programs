//Take input from the file, reverse each word (without reversing any special characters and paste it into new file)

#include <stdio.h>
#include <stdlib.h> // need this for exit(0)
#include <string.h>
#include <ctype.h>

//Function definition of strrev since does not exist on Linux implmentation
char *strrev(char *str)
{
  char *p1, *p2;

  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
  {
    *p1 ^= *p2; //Used bitwise swapping
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;
  char buff[20], newbuff[20]; //The word length should be 20
  int i = 0;

  from = fopen(argv[1], "r");
  to = fopen(argv[2], "w");
  //Taking single character and checking
  while (fscanf(from, "%c", &ch) != EOF)
  {
    //If only digit or alphabet is there, then store it in buff
    if (isalpha(ch) || isdigit(ch))
    {
      buff[i] = ch;
      i++; //Move to next character
    }
    //If any other character than digit or alphabets
    //Null terminate the previous remaining word and then reverse and copy it to the file
    //Then copy the character as it is to the file and reintialize buffer to '\0'
    else if (ch == ' ' || !isalpha(ch) || !isdigit(ch))
    {
      buff[i] = '\0';
      fprintf(to, "%s", strrev(buff));
      fprintf(to, "%c", ch);
      i = 0;
      memset(buff, '\0', sizeof(buff));
    }
  }
  //If EOF file reached, copy this buffer to newbuffer and reverse it
  //Copy the reversed buffer to the file
  if (ch == EOF)
  {
    sscanf(buff, "%s", newbuff);
    //  printf("%s",newbuff);
    fprintf(to, "%s", strrev(newbuff));
  }
  fclose(from);
  fclose(to);

  return 0;
}
