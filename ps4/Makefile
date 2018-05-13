CC=gcc
CFLAGS=-std=c11 -Werror -Wconversion -Wall
LDLIBS=-lm
OUTPUT=textgame

all: main.c world.o room.o backpack.o item.o parser.o game.o container.o command.o
	        $(CC) $(CFLAGS) main.c world.c room.c backpack.c item.c parser.c game.c container.c command.c $(LDLIBS) -o $(OUTPUT)
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

world.o: world.c
		$(CC) $(CFLAGS) world.c $(LDLIBS) -o world.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

room.o: room.c
		$(CC) $(CFLAGS) room.c $(LDLIBS) -o room.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

backpack.o: backpack.c
		$(CC) $(CFLAGS) backpack.c $(LDLIBS) -o backpack.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

item.o: item.c
		$(CC) $(CFLAGS) item.c $(LDLIBS) -o item.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

parser.o: parser.c
		$(CC) $(CFLAGS) parser.c $(LDLIBS) -o parser.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

game.o: game.c
		$(CC) $(CFLAGS) game.c $(LDLIBS) -o game.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

container.o: container.c
		$(CC) $(CFLAGS) container.c $(LDLIBS) -o container.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

command.o: command.c
		$(CC) $(CFLAGS) command.c $(LDLIBS) -o command.o -c
		        cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c

clean:
	        rm $(OUTPUT) *.o
