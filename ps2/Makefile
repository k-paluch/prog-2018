CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm
OUTPUT=topsecret

all: main.c playfair.o bmp.o
	        $(CC) $(CFLAGS) main.c playfair.c bmp.c $(LDLIBS) -o $(OUTPUT)
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

playfair.o: playfair.c
		$(CC) $(CFLAGS) playfair.c $(LDLIBS) -o playfair.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

bmp.o: bmp.c
		$(CC) $(CFLAGS) bmp.c $(LDLIBS) -o bmp.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

clean:
	        rm $(OUTPUT) *.o
