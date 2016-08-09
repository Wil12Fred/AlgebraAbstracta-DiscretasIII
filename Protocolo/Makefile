CC = g++
CFLAGS= -std=c++11 -Wall -pedantic -O -lntl -lm

.SUFFIXES: .cc .o

.cc.o:
	$(CC) -c $(CFLAGS) $<

all: main

main: main.o
	$(CC) -o main $(CFLAGS) main.o

main.o: vaya.h

main.o: ruta.h

main.o: fdigital.h

main.o: pr.h

main.o: gamal.h

main.o: lfcr.h

main.o: xorshift.h

main.o: mersenne_twister.h

main.o: rsa.h

main.o: gordon.h

main.o: criba.h

main.o: miller_rabin.h

main.o: bbs.h

main.o: lucas.h

main.o: funciones.h

main.o: fermat.h

main.o: pollar.h

main.o: main.cc

clean:
	rm -f *.o
	rm -f *.s
	rm -f main
