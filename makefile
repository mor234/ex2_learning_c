

all: prog redi dif	
prog: main.o myBank.o
	gcc -Wall -g myBank.o main.o -o prog
redi:
	./prog<in1.txt>myout1
	./prog<in2.txt>myout2
	./prog<in3.txt>myout3	
	./prog<input.txt>myoutput
dif:
	diff myout1 out1.txt
	diff myout2 out2.txt
	diff myout3 out3.txt
err:
	diff myoutput output.txt

myBank.o: myBank.h myBank.c
	gcc -Wall -g -c myBank.c
main.o:  myBank.h main.c 
	gcc -Wall -g -c main.c
clean:
	rm myBank.o main.o prog Myoutput