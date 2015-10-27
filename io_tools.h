#ifndef IO_TOOLS
#define	IO_TOOLS

void print_char(int length, char* order)
{
	for(int i =0; i<length; i++)
		printf("%c ", order[i]);
	printf("\n");
};

#endif