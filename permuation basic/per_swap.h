#ifndef PER_SWITCH
#define PER_SWITCH

#include "mid_num.h"

class per_swap :public mid_num_de
{
protected:
	char* order;

public:
	per_swap(int s, long r = 0);
	~per_swap(){delete [] order;};
	
	void refresh();
	// void next();
	char* get_order();
	bool change(long amount){ return this->alter(amount); };
};

#endif