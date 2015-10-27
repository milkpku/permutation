#ifndef DICT_LIST
#define DICT_LIST


class dict_list
{
private:
	char *dict;
	int *hash;
	int size;

public:
	dict_list(int n); // build a set which contains n character start from 'a'

	char pop(int k = 0); // pop out the kth min one in the rest set

	~dict_list();
};
#endif