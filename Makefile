all: compile

compile: simpleCSVsorter.c simpleCSVsorter.h
	gcc -Wall -Werror -fsanitize=address simpleCSVsorter.c -o simpleCSVsorter
	#gcc simpleCSVsorter.c -o simpleCSVsorter
clean:
	rm simpleCSVsorter

moves: simpleCSVsorter.c
	cat movie_metadata.csv | ./simpleCSVsorter -c movie_title
