#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define _OPEN_SYS_ITOA_EXT

void generate(int n);
char* strCon(char* s1, char* s2);

int main(int argc, char* argv[])
{
  /*
  if(argc!=2)
  {
    fprintf(stderr, "error, no argument of size inputted");
    return 1;
  }
  char* numb = argv[1];
  int size = atoi(numb);
  */

  generate(100000000);
}

void generate(int n)
{
  FILE *fp;
  char number[20];
  snprintf(number, 20, "%d", n);
  strcat(number, "numbers");
  fp = fopen(number, "w+");
  srand(time(NULL));
  for(int i = 0; i<n; i++)
  {
    int randInt = rand();
    fprintf(fp,"%d ", randInt);
  }
  fclose(fp);
}
