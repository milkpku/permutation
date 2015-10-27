#ifndef ARANGE_LIST
#define ARANGE_LIST


class arange_list
{
private:
	char *dict;
	int *hash;
	int size;

public:
	arange_list(int n); // build a set which contains n character start from 'a'

	char pop(int k = 0); // pop out the kth min one in the rest set

	~arange_list();
};
#endif