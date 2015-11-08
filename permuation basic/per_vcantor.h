#ifndef PER_VCANTOR
#define PER_VCANTOR

#include "mid_num.h"

class per_vcantor :public mid_num_de
{
protected:
	char* order;

public:
	per_vcantor(int s, long r = 0);
	~per_vcantor(){delete [] order;};
	
	void refresh();
	char* get_order();
	bool change(long amount){ return this->alter(amount); };
};

#endif