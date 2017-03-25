// sort methods
// including a simple sorting of an array of bytes using an index table
// (which is way faster than quicksort and bubblesort)
//
// written by Thomas CARTON
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


// sort an array of unsigned char using bubble sort
void bubbleSort(unsigned char *array, unsigned int size)
{
    for (unsigned int c = 0; c < size - 1; ++c)
    {
        for (unsigned int d = 0; d < size - c - 1; ++d)
        {
            if (array[d] > array[d + 1])
	    {
                unsigned char swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }	
}

// sort an array of unsigned char using an index table
void indexSort(unsigned char *array, unsigned int size)
{
    unsigned char *p = array;

    unsigned char *inc = (unsigned char *)malloc(256);
    memset(inc, 0, 256);

    for (unsigned int i = 0; i < size; ++i) ++inc[array[i]];
    for (unsigned int i = 0; i < 256; ++i) while (inc[i]--) *p++ = i;

    free(inc);
}


// helper to print the array

void display(const char *title, unsigned char *array, unsigned int size)
{
    printf("unsigned char %s[] = \n{", title);

    for (unsigned int i = 0; i < size; ++i) printf("%s0x%02X, ", i % 16 ? "" : "\n\t", array[i]);

    printf("\n};\n");
}


// main

int main(int argc, char *argv[])
{
    unsigned size = 100;
    unsigned char *randomValues = (unsigned char *)malloc(size);
    for (unsigned int i = 0; i < size; ++i) randomValues[i] = random();
    display("random", randomValues, size);

    unsigned char *values = (unsigned char *)malloc(size);

    memcpy(values, randomValues, size);
    bubbleSort(values, size);
    display("bubbleSorted", values, size);

    memcpy(values, randomValues, size);
    indexSort(values, size);
    display("indexSorted", values, size);

    free(values);

    free(randomValues);
}
