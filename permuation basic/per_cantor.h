#ifndef PER_CANTOR
#define PER_CANTOR

#include "mid_num.h"

class per_cantor:public mid_num_in
{
protected:
	char* order;

public:
	per_cantor(int s, long r = 0);
	~per_cantor(){delete [] order;};
	
	void refresh();
	char* get_order();
	bool change(long amount){ return this->alter(amount); };
};

#endif