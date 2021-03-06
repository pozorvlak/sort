#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "msort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "print_array.h"
#include "stdio.h"

#define NUM_ALGS 4
char alg_name[NUM_ALGS][16] = { "quicksort", "mergesort", "bubblesort",
        "insertion sort" };

int is_expected(int *actual)
{
        int expected[11] = { 0, 1, 2, 2, 3, 3, 4, 7, 8, 9, 10 };
        int i;
        for (i = 0; i < 11; i++) {
                if (actual[i] != expected[i]) {
                        return 0;
                }
        }
        return 1;
}

int main()
{
        srandom(time(NULL));
        printf("1..%d\n", NUM_ALGS);
        int i;
        for (i = 0; i < NUM_ALGS; i++) {
                int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
                switch(i) {
                        case 0: quicksort(arr, 11); break;
                        case 1: mergesort(arr, 11); break;
                        case 2: bubblesort(arr, 11); break;
                        case 3: insertionsort(arr, 11); break;
                }
                printf("%s %i - %s produces ",
                        (is_expected(arr) ? "ok" : "not ok"),
                        i + 1, alg_name[i]);
                print_array(arr, 11);
        }
        return 0;
}
