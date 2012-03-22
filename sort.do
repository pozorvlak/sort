OBJS="qsort.o msort.o bubblesort.o print_array.o main.o"
redo-ifchange $OBJS
gcc -o $3 $OBJS
