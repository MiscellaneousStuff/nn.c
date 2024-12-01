CC = gcc

all: main

main: main.c
	${CC} main.c -o main

run: main
	./main

clean:
	rm *.o main