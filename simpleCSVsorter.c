#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "simpleCSVsorter.h"

/* ***
 * 	Global Variables
 ****/

int main(int argc, char** argv)
{

	record_list* head = (record_list*)malloc(sizeof(record_list));

	// error check command line arguments
	/*
	if(argc != 3)
	{
		printf("Fatal Error in %s on line %d\nToo Few Arguments.\n", __FILE__, __LINE__);
		return -1;
	}
	*/
	
	// TESTING PUSH AND PRINT
	int arr[] = {10, 20, 30, 40, 50};
	int i;
	for(i = 0; i < 5; i++)
		push(&head, &arr[i], sizeof(int));
	printf("created an integer linked list...\n");
	print_list(head, print_int);
	free(head);

	record_list* new_head = (record_list*)malloc(sizeof(record_list));
	float arr2[] = {2.2, 3.3, 4.4, 5.5, 6.6};
	for(i = 0; i < 5; i++)
		push(&new_head, &arr2[i], sizeof(float));
	printf("created a float linked list...\n"); 
	print_list(new_head, print_float);
	free(new_head);

	record_list* str_list = (record_list*)malloc(sizeof(record_list));
	char* str_arr[200] = {"cheese", "crackers", "wine", "kittens", "love"};
	for(i = 0; i < 5; i++)
		push(&str_list, str_arr[i], strlen(str_arr[i]));
	printf("created a linked list of strings...\n");
	print_list(str_list, print_str);
	free(str_list);
	// END TEST OF PUSH AND PRINT 








	
	return 1;
}

