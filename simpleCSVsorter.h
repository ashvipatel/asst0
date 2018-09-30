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

typedef struct _record_list
{
	char* key_type;
	char* col_values;
	Record* first;
} record_list;



/*****
*
*	Define Global Variables, MACROS, and File Descriptors
*
******/

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
void push(record_list**, void*, size_t);
void print_list(record_list*, void(*fptr)(void*));


/******
 * 	Functions
 *****/


/*
void append_int(list_of_records* head, int* k, char* comp)
{
	// build new node
	Record* newNode = (Record*)malloc(sizeof(Record));
	newNode->key = k;
	newNode->complete = comp;

	if(head->first == NULL)
	{
		head->first = newNode;
		printf("head: %d --> ", *(int*)(head->first->key));
		return;
	}
	Record* tmp = head->first;
	while(tmp->next != NULL)
	{
		printf("tmp: %d --> ", *(int*)(tmp->key));
		tmp = tmp->next;
	}
	// tmp = last node in list, tmp->next == NULL
	tmp = newNode;
	printf("newNode: %d\n", *(int*)(tmp->key));
	return;
}

*/


/* ***
 * 	push() pushes data "k"--in a new Record node--to the front of
 * 	the record_list referenced by head_ref
 ***/
void push(record_list** head_ref, void* k, size_t data_size)
{
<<<<<<< HEAD
printf("------ append ------\n");
	// if list is empty, initialize first node
	if(head->first == NULL)
	{
		Record* newNode = (Record*)malloc(sizeof(Record));

		if(integer==TRUE)
			newNode->key = (int*)k;
		else if(floating == TRUE)
			newNode->key = (float*)k;
		else
			newNode->key = (char*)k;

		newNode->complete = comp;
		head->first = newNode;
		return;
	}
=======
	Record* new_node = (Record*)malloc(sizeof(Record));
	new_node->key = malloc(data_size);
	new_node->key = k;
	new_node->next = (*head_ref)->first;

	(*head_ref)->first = new_node;
}
>>>>>>> from_scratch

/* ***
 * 	print_list() accepts a pointer to a record_list as first arg.
 * 	as second arg accepts one of the following:
 * 		"print_int" if your list contains integer values in key
 * 		"print_float" if your list contains float values in key
 * 		"print_str" if your list containt char* values in key
 * **/
void print_list(record_list* head_ref, void(*fptr)(void*))
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
	//char tmp[20];
	//strcpy(tmp, (char*)k);
	printf("%s ", (char*)k);
}




<<<<<<< HEAD
/* *** 					THIS FUNCTION IS TEMPORARY, TO TEST APPEND()
 * 	write the CSV to STDOUT
 ****/
void print_to_stdout(list_of_records* head)
{
	if(head != NULL)
		printf("%s\n", head->col_values);
	else
		printf("whoops\n");
	Record* tmp = head->first;
	while(tmp != NULL)
	{
		if(integer == TRUE)
			printf("%d --> ", *(int*)tmp->key);
		else if(floating == TRUE)
			printf("%f --> ", *(float*)tmp->key);
		else
			printf("%s -->", *(char*)tmp->key);
		tmp = tmp->next;
	}
	printf("\n");
}
=======





>>>>>>> from_scratch



































