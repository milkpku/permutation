// unit test

#include <iostream>
#include <time.h>
#include "mid_num.h"
#include "io_tools.h"
#include "per_dict.h"
#include "per_cantor.h"
#include "per_vcantor.h"

using namespace std;

int main(int argc, char const *argv[])
{

/////////////////////////////// rank_class
/*
    rank_class test_rank(5, 20);

	printf("%d\n", test_rank.rank_altered());
    printf("%d\n", test_rank.set_rank(30));
    printf("%d\n", test_rank.rank_rank());
    printf("%d\n", test_rank.set_rank(130));
    printf("%d\n", test_rank.rank_max());
    printf("%d\n", test_rank.rank_altered());
*/

/////////////////////////////// mid_num_in
/*
    mid_num_in test_mid_in(5,0);
    
    int* mid_num = test_mid_in.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");
    
    test_mid_in.set_mid(20);
    mid_num = test_mid_in.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");

    test_mid_in.alter(20);
    mid_num = test_mid_in.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");
    
    test_mid_in.alter(-50);
*/

/////////////////////////////// mid_num_de
/*
    mid_num_de test_mid_de(5,0);
    
    int* mid_num = test_mid_de.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");
    
    test_mid_de.set_mid(20);
    mid_num = test_mid_de.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");

    test_mid_de.alter(20);
    mid_num = test_mid_de.get_mid_num();
    for(int i = 0; i<4; i++)
        printf("%d ", mid_num[i]);
    printf("\n");
    
    test_mid_de.alter(-50);
*/


	long beginTime = clock();
    
/////////////////////////////// per_dict

    // per_dict d(5);
    
    // long MAX_RANK = fact(5)-1;
    // long i = 0;
    
    // print_char(5, d.get_order());
    // while (i<MAX_RANK){
    //     d.alter(1);
    //     print_char(5, d.get_order());
	// 	i++;
    // };
    
    
/////////////////////////////// increase

	// FILE* pfile;
	// fopen_s(&pfile, "per_cantor", "w");

    // per_cantor d(10);
    
    // long MAX_RANK = fact(10)-1;
    // long i = 0;
    
    // fprint_char(pfile, 10, d.get_order());
    // while (i<MAX_RANK){
    //     d.alter(1);
    //     fprint_char(pfile, 10, d.get_order());
    //     // d.refresh();
	// 	i++;
    // };
    
    // fclose(pfile);

/////////////////////////////// decrease
    per_vcantor d(5);
    
    long MAX_RANK = fact(5)-1;
    long i = 0;
    
    print_char(5, d.get_order());
    while (i<MAX_RANK){
        d.alter(1);
        print_char(5, d.get_order());
		i++;
    };

/////////////////////////////// switch

    
    long endTime = clock();

    printf("Runting time: %d ms\n", endTime - beginTime);
	system("pause");
    return 0;
}