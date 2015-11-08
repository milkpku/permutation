// unit test

#include <iostream>
#include <time.h>
#include "mid_num.h"
#include "io_tools.h"
#include "per_dict.h"
#include "per_cantor.h"
#include "per_vcantor.h"
#include "per_swap.h"

using namespace std;

int main(int argc, char const *argv[])
{

    int type = -1;
    int n = -1;
    
    while (n<=0)
    {
        printf("Permutation size(<14) = ");
        scanf_s("%d", &n);
        if (n>13)
        {
			printf("Too large. Size shold be smaller than 14. \n");
            n=-1;
        };
    }
    
    while (type<0)
    {
        printf("Which permutation algorithm:\n 0. dict\n 1. cantor\n 2. vcantor\n 3. swap\n type = ");
        scanf_s("%d", &type);
        if (type>3)
        {
            printf("You should input a number no more than 3.\n");
            type=-1;
        };
    }
    
	long beginTime = clock();
	long MAX_RANK = fact(n) - 1;
	long i = 0;
	per_dict d(n);
	per_cantor c(n);
	per_vcantor v(n);
	per_swap s(n);

    switch (type)
    {
        case 0: 
				print_char(n, d.get_order());
				while (i<MAX_RANK){
					d.alter(1);
					print_char(n, d.get_order());
					i++;
				};
				break;

		case 1: 
				print_char(n, c.get_order());
				while (i<MAX_RANK){
					c.alter(1);
					print_char(n, c.get_order());
					i++;
				};
				break;

		case 2: 
				print_char(n, v.get_order());
				while (i<MAX_RANK){
					v.alter(1);
					print_char(n, v.get_order());
					i++;
				};
				break;

		case 3: 
				print_char(n, s.get_order());
				while (i<MAX_RANK){
					s.alter(1);
					print_char(n, s.get_order());
					i++;
				};
				break;
        default:
				break;
    }
    
    long endTime = clock();

    printf("Runting time: %d ms\n", endTime - beginTime);
	system("pause");
    return 0;
}