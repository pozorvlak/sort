#include <assert.h>
#include <stdio.h>

void print_array(int* arr, int size)
{
        int i;
        int last = size - 1;
        for (i = 0; i < last; i++) {
                printf("%d, ", arr[i]);
        }
        printf("%d\n", arr[last]);
}

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
        int less_than = partition(start, size, 0);
        quicksort(start, less_than);
        quicksort(start + less_than + 1, size - less_than - 1);
}

int main() {
        int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
        quicksort(arr, 11);
        print_array(arr, 11);
        return 0;
}
