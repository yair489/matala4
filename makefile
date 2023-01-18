
CC=gcc
OBJ=algo.o graph.o main.o graph.h node.o
NAME = main
CFLAGS = -Wall -Werror -g

all : graph
graph: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o graph  
graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c
algo.o: algo.c graph.h
	$(CC) $(CFLAGS) -c algo.c
node.o: graph.h
	$(CC) $(CFLAGS) -c node.c
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

.PHONY = all clean

clean:
	rm -f *.o *.a graph
	