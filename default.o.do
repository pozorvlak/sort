redo-ifchange $2.c
gcc -o $3 -c $2.c -MMD -MF $2.deps
read DEPS <$2.deps
redo-ifchange ${DEPS#*:}
