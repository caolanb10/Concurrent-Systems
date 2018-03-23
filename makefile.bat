clean
gcc -o serialsort serialsort.c
gcc -o serialsearch serialsearch.c
gcc -o parallelsearch -fopenmp parallelsearch.c
gcc -o parallelsort -fopenmp parallelsort.c
gcc -o numgen generateArraySort.c
numgen.exe