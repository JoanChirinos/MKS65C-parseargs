compile: parse.o
	gcc parse.o

run:
	./a.out

clean:
	-rm -rf ./a.out *.o

parse.o:
	gcc -c parse.c
