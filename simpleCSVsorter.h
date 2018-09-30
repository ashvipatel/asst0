#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*****
*
*	Define Global Variables and File Descriptors
*
******/
char* key_type;

#define STDIN 0
#define STDOUT 1
#define STDERR 2



/*****
 * 
 * 	Define custom types and structs
 *
 *****/
typedef enum _boolean { TRUE = 1, FALSE = 2} boolean;

typedef struct _record
{
	void* key;
	char* complete_record;
	struct _record* next;
} record;



/******
 * 
 * 	Function Prototypes
 *
 ******/
//int readCSV( STDIN, record*, char*):
//int write_to_stdout(record*);
//int write_to_file(<file descriptor?>, record*);
//int clear(record*);



/******
 *
 * 	Functions
 *
 ******/
