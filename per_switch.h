#ifndef PER_SWITCH
#define PER_SWITCH

#include "mid_num.h"

class per_switch:public mid_num_de
{
protected:
	char* order;

public:
	per_switch(int s, long r = 0);
	~per_switch(){delete [] order;};
	
	void refresh();
	// void next();
	char* get_order();
};

#endif