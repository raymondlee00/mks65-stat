ifeq ($(DEBUG), true)		
	CC = gcc -g
else
	CC = gcc
endif

all: main.o
	gcc -o teststat main.o

main.o: main.c
	gcc -c main.c

run:
	./teststat

clean:
	rm *.o
	rm teststat
	rm rand
	rm *~

memcheck:
	valgrind --leak-check=yes ./teststat
