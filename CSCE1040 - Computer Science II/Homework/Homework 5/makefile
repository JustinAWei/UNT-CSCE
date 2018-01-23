CC = g++
CFLAGS = -I.
DFLAGS = -I -g
DEPS = main.h book.h CD.h DVD.h libitem.h libitems.h patron.h patrons.h reference.h transactions.h transaction.h
OBJ = main.o book.o CD.o DVD.o libitem.o libitems.o patron.o patrons.o reference.o transactions.o transaction.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

debug: $(OBJ)
	$(CC) -o $@ $^ $(DFLAGS)
