CC = g++
DEPS = floydwarshall.h dijkstra.h main.h
OBJ = floydwarshall.o dijkstra.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

main.out: $(OBJ)
	$(CC) -o $@ $^

debug.out: $(OBJ)
	$(CC) -o $@ $^ -g
