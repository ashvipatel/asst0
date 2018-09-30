all: compile

compile: simpleCSVsorter.c simpleCSVsorter.h
	gcc -Wall -Werror -fsanitize=address simpleCSVsorter.c -o simpleCSVsorter

clean:
	rm simpleCSVsorter
