CC = gcc
DEBUG = -g -DDEBUG
INCLUDES = $(wildcard *.c)

run: debug_main release_main

debug_main:
ifdef SEED
	$(CC) $(DEBUG) -DSEED=$(SEED) $(INCLUDES) -o debug_main
else
	$(CC) $(DEBUG) $(INCLUDES) -o debug_main
endif

release_main:
	$(CC) $(INCLUDES) -o release_main

clean:
	rm debug_main
	rm release_main