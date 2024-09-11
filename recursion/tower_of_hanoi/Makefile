CC=clang
CFLAGS=-I.
DEPS = 
OBJ = tower_of_hanoi.o 

%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -rf *.o output
	rm a.out 

run: 
	make && ./output

