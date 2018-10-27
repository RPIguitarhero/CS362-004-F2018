//NAME:Kai Kang
//COURSE:CS362 Software Engineering II
//DATE:October 27th 2018 
//ASSIGNMENT:Random testing quiz

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
  int randNum=rand()%95;//selecting my random pool from space(33rd) to DEL(128th) in ASCII table.
  char randChar=randNum+32;
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
static char randStr[6];//using a static variable to return the result string. Referred to:https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
for(int i=0;i<5;i++)//fill the string with randomly generated 5 chars
  {
    randStr[i]=(rand()%16)+101;//because the file only prompt "error" when string "reset" is generated, minimize the random pool from 'e'(101th) to 't'(116th)
  }
    randStr[5]='\0';//set the last char in the string as null character
    return randStr;

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
