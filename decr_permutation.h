#ifndef DECR_PERMUTATION
#define DECR_PERMUTATION

#include "mid_num.h"

class decr_permutation:public mid_num_de
{
protected:
	char* order;

public:
	decr_permutation(int s, long r = 0);
	~decr_permutation(){delete [] order;};
	
	void refresh();
	char* get_order();
};

#endif