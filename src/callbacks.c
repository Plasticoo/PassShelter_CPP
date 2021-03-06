#include <stdio.h>

int table_callback(void* not_used, int argc, char** argv, char** col_name)
{
	int i;
	not_used = 0;

	for (i = 0; i < argc; i++) 
	{
		printf("\t%s\n", argv[i] ? argv[i] : "NULL");	
	}

	return 0;
}

int column_callback(void* not_used, int argc, char** argv, char** col_name)
{
	int i;
	not_used = 0;

	for (i = 0; i < argc; i++) 
	{
		printf("\t%s: %s\n", col_name[i], argv[i] ? argv[i] : "NULL");	
	}

	putchar('\n');

	return 0;
}
