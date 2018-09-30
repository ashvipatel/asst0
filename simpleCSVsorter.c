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

	list_of_records* head = (list_of_records*)malloc(sizeof(list_of_records));

	// error check command line arguments
	/*
	if(argc != 3)
	{
		printf("Fatal Error in %s on line %d\nToo Few Arguments.\n", __FILE__, __LINE__);
		return -1;
	}
	*/

	// TESTING APPEND AND PRINT TO STDOUT
	int a = 8;
	void* ptr = &a;
	char* buff = "this is a comma separated value";

	//print_to_stdout(head);
	append(head, ptr, buff); 
	//print_to_stdout(head);
	append(head, ptr, buff); 
	//print_to_stdout(head);
	append(head, ptr, buff); 
	//print_to_stdout(head);
	append(head, ptr, buff); 
	print_to_stdout(head);

	free(head);
	
	return 1;
}

