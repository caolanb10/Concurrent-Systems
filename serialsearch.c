#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

//linear search algorithm implemented
int linearSearch(int* array, int size, int find)
{
  for(int i = 0; i<size; i++)
  {
    if(array[i] == find)
    {
      printf("%d is found at position: %d. \n",find,i);
      return 1;
    }
  }
  return 0;
}
/*
Program takes 1 parameter, the amount of numbers for the algorithm
to be tested on.
Program terminates otherwise

Data is taken from the same file for all numbers entered

*/
int main(int argc, char* argv[])
{
  if(argc!=2)
  {
    fprintf(stderr, "%s", "error, input quantity parameter");
    return 1;
  }
  clock_t start = clock();
  char* a = argv[1];
  int n = atoi(a);

  //Search for an random index within our range of numbers
  srand(time(NULL));
  int findIndex = rand() / (RAND_MAX/n+1);
  FILE* fp;
  fp = fopen("100000000numbers","r");
  int* array = malloc(n * sizeof(int));

  for(int index = 0; index<n; index++)
  {
    fscanf(fp, "%d", &array[index]);
  }
  int number = array[findIndex];
  linearSearch(array,n,number);
  clock_t end = clock();
  double elapsedTime = (double) (end-start)/CLOCKS_PER_SEC;
  printf("The time elapsed to find a number in an array of size %d is: %f\n",n ,elapsedTime);
}
