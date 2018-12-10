CC=gcc
CFLAGS=-g -Wall
#-Werror
all:deplacements

deplacements: deplacements.c prog.o
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -rfv *.o deplacements