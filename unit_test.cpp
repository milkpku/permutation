// unit test

#include <iostream>
#include "mid_num.h"
#include "pick_list.h"
#include "io_tools.h"
#include "dict.h"

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

/////////////////////////////// pick_list

    pick_list* p = new pick_list(5);
	delete p;
    
    // mid_num_in test_mid_in(5,0);
    // // pick_list* p = new pick_list(5);
    
    // int* mid_num = test_mid_in.get_mid_num();
    
    // for(int i = 0; i<4; i++)
    //     printf("%c ", p->pop(mid_num[i]));
    // printf("%c\n", p->pop());


    // test_mid_in.alter(33);
    // p = new pick_list(5);
    // mid_num = test_mid_in.get_mid_num();
    // for(int i = 0; i<4; i++)
    //     printf("%c ", p->pop(mid_num[i]));
    // printf("%c\n", p->pop());


/////////////////////////////// dict

    // dict d(5);
    
    // long MAX_RANK = fact(5)-1;
    // long i = 0;
    
    // print_char(5, d.get_order());
    // while (i<MAX_RANK){
    //     d.alter(1);
    //     print_char(5, d.get_order());
    // };
    
    
/////////////////////////////// increase


/////////////////////////////// decrease


/////////////////////////////// switch



	system("pause");
    return 0;
}