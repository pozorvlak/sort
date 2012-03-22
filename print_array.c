#include <stdio.h>
#include "print_array.h"

void print_array(int* arr, int size)
{
        int i;
        int last = size - 1;
        for (i = 0; i < last; i++) {
                printf("%d, ", arr[i]);
        }
        printf("%d\n", arr[last]);
}
