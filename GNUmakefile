PROGRAM=test

$(PROGRAM): $(PROGRAM).o
	$(CC) -o $@ $^
	rm $(PROGRAM).o

$(PROGRAM).o: $(PROGRAM).c hash.h

.PHONY: clean
clean:
	rm $(PROGRAM)

CFLAGS=-g -DDEBUG
