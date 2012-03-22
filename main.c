#include <stdlib.h>
#include <time.h>
#include "qsort.h"
#include "print_array.h"

int main() {
        srandom(time(NULL));
        int arr[11] = { 2, 3, 1, 4, 7, 9, 10, 3, 2, 8, 0 };
        quicksort(arr, 11);
        print_array(arr, 11);
        return 0;
}
