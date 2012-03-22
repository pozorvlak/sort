#include "bubblesort.h"

void bubblesort(int *arr, int length)
{
        int sorted = 0;
        while (!sorted) {
                sorted = 1;
                int i;
                for (i = 0; i < length; i++) {
                        if (arr[i] > arr[i + 1]) {
                                sorted = 0;
                                int swap = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = swap;
                        }
                }
        }
}
