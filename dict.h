#ifndef DICT_PERMUTATION
#define DICT_PERMUTATION

class dict{

private:
	void rank_to_mid();
	void mid_to_rank();
	void mid_to_order();
	void order_to_mid();
public:
	int size;
	int rank;
	int* mid_number;
	char* order;

	dict(int s);
	dict(int s, int n);
	dict(int s, char* order);
	dict(int s, int* mid_num);

	bool rank_valid
	bool dict_set_mid(int* mid_num);
	bool dict_set_rank(int rank);
	bool dict_set_order(char* order);
	bool dict_gen(int* mid_num, char* outstream);
	bool dict_increase_mid(int* mid_num, int amount);

	void next();

};

#endif