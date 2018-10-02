#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


/*****
 * 
 * 	Define custom types and structs
 *
 *****/
typedef enum _boolean { TRUE = 1, FALSE = 0} boolean;

typedef struct _Record
{
	void* key;

	char* complete;
	struct _Record* next;
} Record;

typedef struct _record_list
{
	char* col_tokens;
	Record* first;
} record_list;



/*****
*
*	Define Global Variables, MACROS, and File Descriptors
*
******/

// variables to use in tools to determine type of data 
// pointed to by a void*
char* sort_token;
int sort_token_index = 0;
#define IS_INT 0
#define IS_FLOAT 1
#define IS_STRING 2
boolean integer = FALSE;
boolean string = FALSE;
boolean floating = FALSE;
// self-explanatory
int BUFFER_SIZE = 500;
int LINE_SIZE = 1024;
int TOKEN_SIZE = 200;
// file descriptors
#define STDIN 0
#define STDOUT 1
#define STDERR 2


/******
 * 
 * 	Function Prototypes
 *
 ******/
void clear(record_list*);
int get_token_index(char*);
int get_type(void*);
Record* push_new_record(record_list**);
void print_float(void*);
void print_int(void*);
void print_keys(record_list*, void(*fptr)(void*));
void print_str(void*);
int readCSV(record_list**);


/******
 * 	Functions
 *****/


void clear(record_list* head_ref)
{
//	Record* curr = head_ref->first;
//	Record* prev = curr;
	// free head and its contents
	free(head_ref->col_tokens);
	free(head_ref);
	// iterate through list and free each record node's contents
	// then free the record node
}



void* get_key(char* a)
{
	void* k;
	k = a;
	return k;
}


/* ***
 *	get_token_index(char*) utilizes strtok() to parse the given string
 *	and split it up into tokens, between the hard-coded delimeter: ","
 *	RETURNS:the index of the sort token if found in the first line of the
 *	CSV, else returns -1
 ****/
int get_token_index(char* a)
{
	int index = 0;
	char* delim = ",";
	char* str = (char*)malloc(LINE_SIZE);
	char* tok;
	str = strcpy(str, a);
	// first call of strtok on str. returns first token of str 
	// before delimiter: ','
	tok = strtok(str, delim);
	if(strcmp(tok, sort_token) == 0)
	{ // FOUND TOKEN! Return index (should be 0)
		free(str);
		return index;
	}
	else // increment index and constinue parsing
	{
		index++;
	}
	do
	{
		tok = strtok(NULL, delim);
		if(tok == NULL)
		{
			return -1;
		}
		// compare token to sort_token
		if(strcmp(tok, sort_token) == 0)
		{ // FOUND TOKEN! Return index
			free(str);
			return index;
		}
		else // continue parsing for next token
		{
			index++;
		}
	} while(tok);
	return -1;
}
int readCSV(record_list** head_ref)
{
	char* buffer = (char*)malloc(BUFFER_SIZE);
	(*head_ref)->col_tokens = (char*)malloc(LINE_SIZE);
	int line_len = strlen((*head_ref)->col_tokens);

	if(buffer == NULL)
	{
		printf("Fatal Error in %s on line %d\nUnable to Allocate Memory for Buffer\n", __FILE__, __LINE__);
		return -1;
	}

	int count_lines = 0;
	

	// READ THE HEADER OF THE CSV TO GET COL TOKENS
	do
	{
		read(STDIN, buffer, 1);
		if(line_len < LINE_SIZE)
		{
			// append buffer to col_tokens
			(*head_ref)->col_tokens = strcat((*head_ref)->col_tokens, buffer);
			line_len++;
		}
		else // line_len exceeds memory allocateed for line
		{
			LINE_SIZE += (LINE_SIZE/2);
			(*head_ref)->col_tokens = (char*)realloc((*head_ref)->col_tokens, LINE_SIZE);
			// append buffer to col_tokens
			(*head_ref)->col_tokens = strcat((*head_ref)->col_tokens, buffer);
			line_len++;
		}
	}
	while(strcmp(buffer, "\n") != 0);
	count_lines++;
	// get the token index to fetch keys for each record upon reading new line
	sort_token_index = get_token_index((*head_ref)->col_tokens);
	if(sort_token_index == -1)
	{
		printf("Fatal Error in %s on line %d\nSort Token not found in CSV\n", __FILE__, __LINE__);
		return -1;
	}
	else

	// READ THE BODY OF THE CSV
	//Record* tmp_record;
	do
	{
		Record* tmp = push_new_record(head_ref);
		read(STDIN, buffer, 1);
		line_len = strlen(tmp->complete);
		if(line_len < LINE_SIZE)
		{
			// append buffer to new Record's complete string
			tmp->complete = strcat(tmp->complete, buffer);
		}
		else // line_len exceeds memory allocated for new Record's complete string
		{
			LINE_SIZE += (LINE_SIZE/2);
			tmp->complete = (char*)realloc(tmp->complete, LINE_SIZE);
			tmp->complete = strcat(tmp->complete, buffer);
		}
		} while(strcmp(buffer, "\n") != 0);
		// Reached end of a line in CSV.
		// get key for line and continue to next line.
		get_key(tmp);

	} while(read(STDIN, buffer, 1) != 0);
        	
	printf("number of lines in CSV: %d\n", count_lines);
        free(buffer);
	return 1;
}


/* ***
 * 	get_type deciphers the type which is pointed to by void* n
 * 	returns IS_INT, IS_FLOAT, or IS_STRING
 * 	ints, floats, and strings (char* 's) are all we're concerned about for
 * 	this project.
 ****/
int get_type(void* n)
{
	return 69;	
}

/* ***
 * 	push_record() pushes data "k"--in a new Record node--to the front of
 * 	the record_list referenced by head_ref
 ***/
Record* push_new_record(record_list** head_ref)
{
	Record* new_node = (Record*)malloc(sizeof(Record));
	new_node->complete = (char*)malloc(LINE_SIZE);
	new_node->next = (*head_ref)->first;
	(*head_ref)->first = new_node;
	return new_node;
}

/* ***
 * 	print_keys() accepts a pointer to a record_list as first arg.
 * 	as second arg accepts one of the following:
 * 		"print_int" if your list contains integer values in key
 * 		"print_float" if your list contains float values in key
 * 		"print_str" if your list containt char* values in key
 * **/
void print_keys(record_list* head_ref, void(*fptr)(void*))
{
	Record* ptr = head_ref->first;
	while(ptr)
	{
		(*fptr)(ptr->key);
		ptr = ptr->next;
	}
	printf("\n");
}
void print_int(void* k)
{
	printf("%d ", *(int*)k);
}
void print_float(void* k)
{
	printf("%f ", *(float*)k);
}
void print_str(void* k)
{
	printf("%s ", (char*)k);
}












































