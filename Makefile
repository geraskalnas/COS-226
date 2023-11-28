CC = gcc
CFLAGS = -g -Wall -Wextra

all: encrypt brute decrypt

encrypt: encrypt.o key.o
	$(CC) $(CFLAGS) -o encrypt encrypt.o key.o

encrypt.o: encrypt.c key.h
	$(CC) $(CFLAGS) -c -o encrypt.o encrypt.c

key.o: key.c key.h
	$(CC) $(CFLAGS) -c -o key.o key.c

brute: brute.o key.o
	$(CC) $(CFLAGS) -o brute brute.o key.o

brute.o: brute.c key.h
	$(CC) $(CFLAGS) -c -o brute.o brute.c

decrypt: decrypt.o key.o
	$(CC) $(CFLAGS) -o decrypt decrypt.o key.o

decrypt.o: decrypt.c key.h
	$(CC) $(CFLAGS) -c -o decrypt.o decrypt.c


clean:
	rm -f encrypt brute decrypt *.o