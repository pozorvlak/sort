#include <stdlib.h>
#include "qsort.h"
#include "print_array.h"

int partition(int *start, int size, int pivot_index)
{
        int pivot = start[pivot_index];
        // move pivot to end
        // in fact, we can just rip it out since we know what it is
        // and we won't need to move it.
        int swap = start[size - 1];
        start[pivot_index] = swap;
        int index = 0;
        int i;
        for (i = 0; i < size - 1; i++) {
                print_array(start, size);
                if (start[i] < pivot) {
                        swap = start[index];
                        start[index] = start[i];
                        start[i] = swap;
                        index++;
                }
        }
        start[size - 1] = start[index];
        start[index] = pivot;
        return index;
}

void quicksort(int *start, int size)
{
        if (size <= 1) {
                return;
        }
        int pivot_index = random() * size / RAND_MAX;
        if (pivot_index == size) {
                pivot_index--;
        }
        int less_than = partition(start, size, pivot_index);
        quicksort(start, less_than);
        quicksort(start + less_than + 1, size - less_than - 1);
}

