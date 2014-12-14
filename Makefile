CC = gcc
LDFLAGS =
CFLAGS = -Wall -O3
OBJECTS = fastfibbo.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

fastfibbo: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

debug:	CFLAGS= -Wall -O3 -g
debug: 	$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o fastfibbo-$@ $(LDFLAGS)

clean:
	@echo cleaning oop
	@rm -f $(OBJECTS)
purge:
	@echo purging oop
	@rm -f $(OBJECTS)
	@rm -f fastfibbo
	@rm -f fastfibbo-debug
