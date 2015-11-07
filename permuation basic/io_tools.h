#ifndef IO_TOOLS
#define	IO_TOOLS

const int A = int('a');

void print_char(int length, char* order)
{
	for(int i =0; i<length; i++)
		printf("%c ", order[i]);
	printf("\n");
};

void fprint_char(FILE* pfile, int length, char* order)
{
	for(int i =0; i<length; i++)
		fprintf(pfile, "%c ", order[i]);
	fprintf(pfile, "\n");
};

#endif