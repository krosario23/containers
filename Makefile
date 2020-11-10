all: prog

prog: main.o containers.a
	gcc -lm -o prog main.o -L. containers.a

main.o: main.c
	gcc -O -c main.c

common.o: common.c containers.h
	gcc -O -c common.c

list.o: list.c containers.h
	gcc -O -c list.c

pair.o: pair.c containers.h
	gcc -O -c pair.c

containers.a: common.o list.o pair.o
	ar rcs containers.a common.o list.o pair.o

libs: containers.a

clean:
	rm -f prog *.o *.a *.gch
