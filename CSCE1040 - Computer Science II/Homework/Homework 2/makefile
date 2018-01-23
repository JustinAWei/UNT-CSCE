CFLAGS=-I.
DEPS = structures.h functions.h

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)

main: main.o functions.o
	g++ -o main main.o functions.o $(CFLAGS)
