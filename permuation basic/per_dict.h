#ifndef PER_DICT
#define PER_DICT

#include "mid_num.h"

class per_dict :public mid_num_in
{
protected:
	char* order;

public:
	per_dict(int s, long r = 0);
	~per_dict(){delete [] order;};
	
	void refresh();
	bool next();
	char* get_order();
	bool change(long amount){ return this->alter(amount); };
};

#endif