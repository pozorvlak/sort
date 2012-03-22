#include "msort.h"
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int *left, int lsize, int *right, int rsize)
{
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < lsize && j < rsize) {
                if (left[i] < right[j]) {
                        arr[k++] = left[i++];
                } else {
                        arr[k++] = right[j++];
                }
        }
        while (i < lsize) {
                arr[k++] = left[i++];
        }
        while (j < rsize) {
                arr[k++] = right[j++];
        }
}

void mergesort(int *arr, int size)
{
        if (size <= 1) return;
        int lsize = size / 2;
        int rsize = size - lsize;
        int *left  = (int*) malloc(sizeof(int) * lsize);
        int *right = (int*) malloc(sizeof(int) * rsize);
        memcpy(left, arr, sizeof(int) * lsize);
        memcpy(right, arr + lsize, sizeof(int) * rsize);
        mergesort(left, lsize);
        mergesort(right, rsize);
        merge(arr, left, lsize, right, rsize);
        free(left);
        free(right);
}

