all: randfile.o
	gcc -o randfile.out randfile.o

randfile.o: randfile.c
	gcc -c randfile.c

run: randfile.out
	./randfile.out

clean:
	rm rand
	rm randfile.o
	rm randfile.out