all: main.o library.o linkedlist.o
	gcc -o output main.o library.o linkedlist.o

main.o: main.c linkedlist.h library.h
	gcc -c main.c

library.o: library.c library.h linkedlist.h
	gcc -c library.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

run:
	./output