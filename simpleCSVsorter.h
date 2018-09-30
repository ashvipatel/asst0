#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/*****
 * 
 * 	Define custom types and structs
 *
 *****/
typedef enum _boolean { TRUE = 1, FALSE = 2} boolean;

typedef struct _Record
{
	void* key;
	char* complete;
	struct _Record* next;
} Record;



/*****
*
*	Define Global Variables, MACROS, and File Descriptors
*
******/
char* key_type;

boolean integer = FALSE;
boolean string = FALSE;
boolean floating = FALSE;

#define STDIN 0
#define STDOUT 1
#define STDERR 2



/******
 * 
 * 	Function Prototypes
 *
 ******/
void append(Record*, void*, char*);
//int clear(Record*);
//int readCSV( STDIN, Record*, char*):
void print_to_stdout(Record*);
//int write_to_file(<file descriptor?>, Record*);



/******
 *
 * 	Functions
 *
 ******/

/* ***
 * 	appends "key" to the end of the linked list beginning at "head"
 ****/
void append(Record* head, void* k, char* comp)
{
printf("------ append ------\n");
	// cast type of key before appending to list
	if(integer == TRUE)
	{
		k = (int*)k;
	}
	else if(floating == TRUE)
		k = (float*)k;
	else
		k = (char*)k;

	// if list is empty, initialize "head"
	if(head == NULL)
	{
		Record* newNode = (Record*)malloc(sizeof(Record));
		newNode->key = (void*)k;
		newNode->complete = comp;
		head = newNode;
		//head->next = NULL;
		return;
	}

	Record* tmp = head->next;
	
	while(tmp != NULL)
	{
		printf("tmp = %s -- ", tmp->complete);
		tmp = tmp->next;
	}
	printf("\n");
	Record* newNode = (Record*)malloc(sizeof(Record));
	newNode->key = k;
	newNode->complete = comp;
	newNode->next = NULL;
	tmp = newNode;
}




/* *** 					THIS FUNCTION IS TEMPORARY, TO TEST APPEND()
 * 	write the CSV to STDOUT
 ****/
void print_to_stdout(Record* head)
{
	printf("the problem has been with this fucking print function all along!\n");
	Record* tmp = head->next;
	while(tmp != NULL)
	{
printf("i give up\n");
		printf("head != NULL\n");
		printf("%s -->", tmp->complete);
		tmp = tmp->next;
	}
	printf("\n");
}



































