#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "msort.h"
#include "print_array.h"
#include "stdio.h"

#define NUM_ALGS 2
char alg_name[NUM_ALGS][16] = { "quicksort", "mergesort" };

int is_sorted(int *arr, int length) {
        int i = 0;
        while (i++ < length - 2) {
                if (arr[i] > arr[i + 1]) {
                        return 0;
                }
        }
        return 1;
}

int main() {
        srandom(time(NULL));
        printf("1..%d\n", NUM_ALGS);
        int i;
        for (i = 0; i < NUM_ALGS; i++) {
                int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
                switch(i) {
                        case 0: quicksort(arr, 11); break;
                        case 1: merge_sort(arr, 11); break;
                }
                printf("%s %i - %s produces ",
                        (is_sorted(arr, 11) ? "ok" : "not ok"),
                        i + 1, alg_name[i]);
                print_array(arr, 11);
        }
        return 0;
}
