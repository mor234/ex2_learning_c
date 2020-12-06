

all: prog

prog: main.o myBank.o
	gcc -Wall -g myBank.o main.o -o prog
	
myBank.o: myBank.h myBank.c
	gcc -Wall -g -c myBank.c
main.o:  myBank.h main.c 
	gcc -Wall -g -c main.c
clean:
	rm myBank.o main.o prog 