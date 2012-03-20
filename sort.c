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

void quicksort(int *start, int size)
{
        if (size <= 1) {
                return;
        }
        int pivot = *start;
        int less_than = 0;
        int i;
        for (i = 0; i < size; i++) {
                if (start[i] < pivot) {
                        less_than++;
                }
        }
        int swap = start[less_than];
        start[less_than] = pivot;
        *start = swap;
        int j;
        int swap_me = less_than;
        /* find all elts in right half greater than pivot,
           swap them into the left half. */
        for (j = 0; j < less_than; j++) {
                if(start[j] >= pivot) {
                        while (start[++swap_me] >= pivot)
                               ;
                        assert(swap_me <= size);
                        swap = start[swap_me];
                        start[swap_me] = start[j];
                        start[j] = swap;
                }
        }
        quicksort(start, less_than);
        quicksort(start + less_than + 1, size - less_than - 1);
}

int main() {
        int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
        quicksort(arr, 11);
        print_array(arr, 11);
        return 0;
}
