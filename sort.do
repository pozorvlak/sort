OBJS="qsort.o print_array.o main.o"
redo-ifchange $OBJS
gcc -o $3 $OBJS
