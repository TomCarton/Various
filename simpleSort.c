// sort
// simple sorting of an array of bytes
// way faster than quicksort and bubblesort
//
// written by Thomas CARTON
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


// sort an array of unsigned char
void sort(unsigned char *array, unsigned int size)
{
    unsigned char *p = array;

    unsigned char *inc = (unsigned char *)malloc(256);
    memset(inc, 0, 256);
	
    for (unsigned int i = 0; i < size; ++i) ++inc[array[i]];
    for (unsigned int i = 0; i < 256; ++i) while (inc[i]--) *p++ = i;

    free(inc);
}


// helper to print the array

void display(unsigned char *array, unsigned int size)
{
    printf("unsigned char array[] = {");

    for (unsigned int i = 0; i < size; ++i)
    {
	printf("%3d, ", array[i]);
    }

    printf("};\n");
}


// main

int main(int argc, char *argv[])
{
    unsigned char values[] = { 5, 1, 37, 2, 7, 15, 27, 23, 0, 2, 23, 0, 23, 4, };
    unsigned size = sizeof(values);

    display(values, size);

    sort(values, size);

    display(values, size);
}
