DEPS =sum.h

%.o: %.c $(DEPS)
		cc -c -o $@ $<

sum: main.o sum.o
		cc -o sum main.o sum.o

clean:
		rm *.o
		rm sum

run:
		./sum < data
