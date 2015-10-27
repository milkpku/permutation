#ifndef DICT_PERMUTATION
#define DICT_PERMUTATION

#include "mid_num.h"

class dict:public mid_num_in
{
protected:
	char* order;

public:
	dict(int s, long r = 0);
	~dict(){delete [] order;};
	
	void refresh();
	char* get_order();
};

#endif