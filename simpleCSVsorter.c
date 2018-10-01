#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "simpleCSVsorter.h"

/* ***
 * 	Global Variables
 ****/

int main(int argc, char** argv)
{

	record_list* head = (record_list*)malloc(sizeof(record_list));

	// error check command line arguments
	if(argc != 3)
	{
		printf("Fatal Error in %s on line %d\nToo Few Arguments.\n", __FILE__, __LINE__);
		return -1;
	}
	// simpleCSVsort only accepts '-c' as a sorting method (column)
	else if(strcmp(argv[1], "-c") != 0)
	{
		printf("Fatal Error in %s on line %d\nInvalid Option: %s\n", __FILE__, __LINE__, argv[1]);
		return -1;
	}
	// args are correct so far. read key_type from command line args
	else
	{
		sort_token = argv[2];
	}

	// TEST READ FROM STDIN
	if(readCSV(&head) == -1)
		return -1;
	clear(head);
	return 1;
}

