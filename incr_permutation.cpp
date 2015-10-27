#include <iostream>
#include "incr_permutation.h"
using namespace std;

incr_permutation::incr_permutation(int s, long r) : mid_num_in(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* incr_permutation::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void incr_permutation::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	
	// build incr_permutation
	for (int i = 0; i < size; i++)
		hash[i] = size - i - 1;
	
	// pop out order
	for(int i=0; i<this->mid_length; i++)
	{
		int k = this->mid_num[i];
		
		if (k>=size)
		{
			printf("Invalid mid_num!\n");
			return;
		};
		
		this->order[hash[k]] = char(this->mid_length - i + A);
		
		// renew the hash list
		size--;
		for (int j = k; j < size; j++)
			hash[j] = hash[j+1];
	}
	this->order[hash[0]] = char(A);
	
	this->altered = false;
}
