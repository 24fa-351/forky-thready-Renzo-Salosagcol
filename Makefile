all: main.o

main.o: main.c
	gcc -o main main.c

clear:
	rm -f main results.txt

test: main.o
	./main 5 1

print: main.o
	./main 10 1
	./main 10 2
	./main 5 1
	./main 5 2

time: main.o
	time ./main
