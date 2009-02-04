CFLAGS	=	-std=c99 -pedantic -ggdb -Wall # -Werror -DAVL_ALLOC_COUNT
CC		=	gcc $(CFLAGS)
LIBS	=	-lraptor

all: main

parse: parse.c hexastore.o index.o terminal.o vector.o head.o avl.o nodemap.o
	$(CC) $(INC) $(LIBS) -o parse parse.c hexastore.o index.o terminal.o vector.o head.o avl.o nodemap.o

avl-test: avl-test.c avl.o
	$(CC) $(INC) avl-test.c avl.o

avl.o: avl.c avl.h
	$(CC) $(INC) -c avl.c

main: main.c hexastore.o index.o terminal.o vector.o head.o avl.o nodemap.o
	$(CC) $(INC) main.c hexastore.o index.o terminal.o vector.o head.o avl.o nodemap.o

hexastore.o: hexastore.c hexastore.h index.h head.h vector.h terminal.h
	$(CC) $(INC) -c hexastore.c

index.o: index.c index.h terminal.h vector.h head.h
	$(CC) $(INC) -c index.c

terminal.o: terminal.c terminal.h
	$(CC) $(INC) -c terminal.c

vector.o: vector.c vector.h terminal.h
	$(CC) $(INC) -c vector.c

head.o: head.c head.h vector.h terminal.h avl.h
	$(CC) $(INC) -c head.c

nodemap.o: nodemap.c nodemap.h avl.h
	$(CC) $(INC) -c nodemap.c

clean:
	rm -f parse
	rm -f *.o
	rm -f a.out
	rm -rf a.out.dSYM
	rm -rf parse.dSYM

