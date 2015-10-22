#ifndef PICK_LIST
#define PICK_LIST


class pick_list
{
private:
	char *dict;
	int *hash;
	int size;

public:
	pick_list(int n); // build a set which contains n character start from 'a'

	char pop(int k); // pop out the kth min one in the rest set

	~pick_list(){
		delete(hash);
		delete(dict);
	}
};
#endif