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

typedef struct _list_of_records
{
	char* col_values;
	Record* first;
} list_of_records;



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
void append(list_of_records*, void*, char*);
//int clear(Record*);
//int readCSV( STDIN, Record*, char*):
void print_to_stdout(list_of_records*);
//int write_to_file(<file descriptor?>, Record*);



/******
 *
 * 	Functions
 *
 ******/

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
 * 	appends "key" to the end of the linked list beginning at "head"
 ****/
void append(list_of_records* head, void* k, char* comp)
{
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

	// head->first has been initialized
	Record* tmp = head->first;
	
	while(tmp->next != NULL)
	{
		printf("tmp = %s -- ", tmp->complete);
		tmp = tmp->next;
	}
	printf("\n");
	// allocte mem for new node. insert appropriately casted k
	Record* newNode = (Record*)malloc(sizeof(Record));
	if(integer==TRUE)
		newNode->key = (int*)k;
	else if(floating == TRUE)
		newNode->key = (float*)k;
	else
		newNode->key = (char*)k;
	// append new node to list
	newNode->complete = comp;
	//newNode->next = NULL;
	tmp->next = newNode;
}




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



































