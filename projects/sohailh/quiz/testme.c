/*
* Name: Haris Sohail
* Date: 05/02/2018
* CS362 - Random Testing Quiz
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int randNum;		//Random Int
    char x; 		    	//Holds result char

    //Choose random int in ASCII range
    randNum = rand() % (127 - 0 + 1) + 0;
 	//Set and return as char	
    x = randNum;
    return x;
}

char *inputString()
{
    int y;							//For loop initialization 
    int randNum; 						//Random Int
    char holder[6] = {'r', 'e', 's', 'e', 't', '\0'};		//Holds selection for random chars
    char result[6];						//Holds result string to return

    
  	//Loop setting result string randomly assigned characters
    for(y=0; y<6; y++)
    {
    	randNum = rand() % (5 - 0 + 1) + 0;
    	result[y] = holder[randNum];
    }

    //Assign and return pointer
    char *ptr = result;
    return ptr;
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
    //Return and print are never executed 
    //printf("ALL TESTS PASSED.\n");
    return 0;
}
