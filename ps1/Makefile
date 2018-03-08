CC=gcc
CFLAGS=-std=c11 -Werror -Wall -Wconversion
LDLIBS=-lm
OUTPUT=game

all: game

game: main.c k.o hof.o ui.o
	        $(CC) $(CFLAGS) main.c k.c hof.c ui.c $(LDLIBS) -lcurses -o $(OUTPUT)
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

k.o: k.c
	        $(CC) $(CFLAGS) k.c $(LDLIBS) -o k.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

hof.o: hof.c
	        $(CC) $(CFLAGS) hof.c $(LDLIBS) -o hof.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

ui.o: ui.c
	        $(CC) $(CFLAGS) ui.c $(LDLIBS) -o ui.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

clean:
	        rm $(OUTPUT) *.o
