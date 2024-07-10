CC = gcc
CFLAGS = -Wall -Wextra -g

all: pendu

pendu: main.o jeu.o
	$(CC) $(CFLAGS) -o pendu main.o jeu.o

main.o: main.c jeu.h
	$(CC) $(CFLAGS) -c main.c

jeu.o: jeu.c jeu.h
	$(CC) $(CFLAGS) -c jeu.c

clean:
	rm -f *.o pendu

