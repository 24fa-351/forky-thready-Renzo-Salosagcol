all: main.o

main.o: main.c
	gcc -o main main.c

clear:
	rm -f main results.txt

test: main.o
	./main 5 1

print: main.o
	echo "Running ./main with args 10 and 1\n" >> results.txt
	./main 10 1 > results.txt

	echo "\nRunning ./main with args 10 and 2:\n" >> results.txt
	./main 10 2 >> results.txt

	echo "\nRunning ./main with args 5 and 1\n" >> results.txt
	./main 5 1 >> results.txt

	echo "\nRunning ./main with args 5 and 2\n" >> results.txt
	./main 5 2 >> results.txt

time: main.o
	time ./main
