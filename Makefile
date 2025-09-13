all: calculator

calculator: test.o wrapper.o file1.o file2.o file3.o
	gcc -o calculator test.o wrapper.o file1.o file2.o file3.o

test.o: test.c
	gcc -c test.c
wrapper.o: wrapper.c file1.h
	gcc -c wrapper.c
file1.o: file1.c file1.h file2.h
	gcc -c file1.c
file2.o: file2.c file2.h file3.h
	gcc -c file2.c
file3.o: file3.c file3.h
	gcc -c file3.c

clean:
	rm -f *.o calculator
