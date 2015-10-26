#ifndef DICT_PERMUTATION
#define DICT_PERMUTATION

class dict: public mid_num_in
{
protected:
	char* order;
	bool refreshed;

public:
	dict(int s, int r = 0);
	void refresh();
	char* order()
};

#endif