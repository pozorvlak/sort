OBJS="qsort.o msort.o print_array.o main.o"
redo-ifchange $OBJS
gcc -o $3 $OBJS
