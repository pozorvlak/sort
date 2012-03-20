#include <assert.h>
#include <stdio.h>

void quicksort(int *start, int size)
{
        if (size = 0) {
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
        int arr[5] = { 2, 3, 1, 4, 0 };
        quicksort(arr, 5);
        int i;
        for (i = 0; i < 4; i++) {
                printf("%d, ", arr[i]);
        }
        printf("%d\n", arr[5]);
}
