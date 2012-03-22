#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "msort.h"
#include "print_array.h"

int main() {
        srandom(time(NULL));
        int i;
        for (i = 0; i < 2; i++) {
                int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
                switch(i) {
                        case 0: quicksort(arr, 11); break;
                        case 1: merge_sort(arr, 11); break;
                }
                print_array(arr, 11);
        }
        return 0;
}
