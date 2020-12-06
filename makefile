

all: prog 

prog: main.o myBank
	gcc -Wall -g -o prog main.o myBank
	
myBank: myBank.o
	ar -rcs myBank myBank.o
	
myBank.o: myBank.h myBank.c
	gcc -Wall -g -c myBank.c

main.o:  myBank.h main.c 
	gcc -Wall -g -c main.c

clean:
	rm *.o prog 