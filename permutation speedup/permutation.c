#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithm.h"

double benchmark(int type, int n)
{
	long launch, done;
	
	launch = clock();
	
	switch (type)
	{
		case 0:
			dict_perm(n);
			break;
		case 1:
			dict_perm_new(n);
			break;
		case 2:
			adj_perm(n);
			break;
		case 3:
			heap_perm(n);
			break;
		default:
			break;
	}
	
	done = clock();
	
	return 1000.0*(done - launch) / CLOCKS_PER_SEC;
}


int main(int argc, char const *argv[])
{
	double runtime[4][3][10]; // [type][{10,11,12}][test{1~10}]
	FILE *result = fopen("benchmark.out", "w");
	
	
	for(int i = 0; i<4; i++)
		for(int j = 0; j<3; j++)
			for(int k = 0; k<10; k++)
				runtime[i][j][k] = benchmark(i, j+10);
			
	for(int j = 0; j<3; j++)
	{
		fprintf(result, "n = %d\n", j + 10);
		for(int i = 0; i<4; i++)
		{
			switch (i)
			{
				case 0:
					fprintf(result, "dict     ");
					break;
				case 1:
					fprintf(result, "dict_new ");
					break;
				case 2:
					fprintf(result, "adj      ");
					break;
				case 3:
					fprintf(result, "heap     ");
					break;
				default:
					break;
			}
			
			for(int k = 0; k<10; k++)
				fprintf(result, "%8.1lf ", runtime[i][j][k]);
			fprintf(result, "\n");
		}
			
		fprintf(result, "\n\n");
	}
	
	fclose(result);
	return 0;
}