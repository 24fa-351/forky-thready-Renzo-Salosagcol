all: main.o

main.o: main.c
	gcc -o main main.c

clear:
	rm -f main

test: main.o
	./main 5 3

time: main.o
	time ./main 