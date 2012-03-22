#include "insertionsort.h"

void insertionsort(int * arr, int length)
{
        int i;
        /* Invariant: the array is sorted below the i'th element */
        for (i = 0; i < length; i++) {
                int new_elt = arr[i];
                int j = i;
                /* shift all elements below the new one up until we find the
                 * right spot to insert the new element */
                while (--j >= 0 && arr[j] > new_elt) {
                        arr[j + 1] = arr[j];
                }
                /* j is now -1 or the first index s.t. arr[j] <= new_elt */
                arr[j + 1] = new_elt;
        }
}
