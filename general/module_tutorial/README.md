THIS IS HOW TO COMPILE ALL THREE OF THEM:
First write:
$ gcc -c main.c
and
$ gcc -c point.c
this will create two object files (point.o & main.o)

Finally compile these two with:
$ gcc point.o main.o

This will create the executable file (a.out)
