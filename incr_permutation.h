#ifndef INCR_PERMUTATION
#define INCR_PERMUTATION

#include "mid_num.h"

class incr_permutation:public mid_num_in
{
protected:
	char* order;

public:
	incr_permutation(int s, long r = 0);
	~incr_permutation(){delete [] order;};
	
	void refresh();
	char* get_order();
};

#endif