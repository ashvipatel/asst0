#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "simpleCSVsorter.h"



int main(int argc, char** argv)
{
	//char* buffer;

	// error check command line arguments
	if(argc != 3)
	{
		printf("Fatal Error in %s on line %d\nToo Few Arguments.\n", __FILE__, __LINE__);
		return -1;
	}

	//key_type = argv[2];
	integer = TRUE;	

	//  build a little record list to test append() and print_to_stdout()
	//Record* head = (Record*)malloc(sizeof(Record));
	Record* head = NULL;
	//head -> next = NULL;

	append(head, (void*)2, "cheese");
//	print_to_stdout(head);
	append(head, (void*)2, "dino");
//	print_to_stdout(head);
	append(head, (void*)2, "wonka");
//	print_to_stdout(head);
	append(head, (void*)2, "grape");
//	print_to_stdout(head);
	append(head, (void*)2, "error");
	print_to_stdout(head);

	return 1;
}

