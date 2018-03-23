#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <omp.h>

int partition(int array[], int low, int high);
void quicksort(int array[], int low, int high);
void swap(int* i, int* j);
void printArray(int array[], int n);


//Quickosrt algorithm
void swap(int* i, int* j)
{
  int a = *i;
  *i = *j;
  *j = a;
}

void quicksort(int array[], int low, int high)
{
  if(low<high)
  {
    int index = partition(array, low, high);
    #pragma omp parallel sections
    {
      #pragma omp section
      {
        quicksort(array, low, index-1);
      }
      #pragma omp section
      {
        quicksort(array, index+1, high);
      }
    }
  }
}

int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = ( low-1 );
  for(int j = low; j<=high-1;j++)
  {
    if(array[j]<=pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i+1], &array[high]);
  return(i+1);
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
    fprintf(stderr, "error, enter a number as a parameter");
    return 1;
  }

  //Begin timing serial sorting program
  clock_t begin = clock();
  char* a = argv[1];
  int size = atoi(a);

  //Opens data set for recieving data
  FILE* fp;
  fp = fopen("100000000numbers","r");
  int* array = malloc(size * sizeof(int));
  //Reads data
  for(int index = 0; index<size; index++)
  {
    fscanf(fp, "%d", &array[index]);
  }
  quicksort(array, 0, size-1);
  printf("%d\n", size);

  //End timing and calculate run-time
  clock_t end = clock();
  double totalTime = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("The time elapsed to sort an array of size %d is: %f\n",size, totalTime);
  return 0;
}
