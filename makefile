#makefiile for project 2

C=gcc

FLAGS = -g -c -Wall 

LINK = -lpthread

mtCollatz: mtCollatz.o collatz.o thread.o
	   $(C) mtCollatz.o collatz.o thread.o -o mtCollatz $(LINK)

mtCollatz.o: mtCollatz.c collatz.h thread.h
	     $(C) $(FLAGS) mtCollatz.c

collatz.o: collatz.c collatz.h
	   $(C) $(FLAGS) collatz.c

thread.o: thread.c thread.h collatz.h 
	  $(C) $(FLAGS) thread.c 

clean:
	rm *.o mtCollatz
