#include <iostream>
#include "incr_permutaion.h"
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
	char* pool = new char[size];
	
	// build incr_permutation
	for (int i = 0; i < size; i++)
		hash[i] = size - i - 1;
	
	// pop out order
	for(int i=0; i<this->length-1;i++)
	{
		int k = this->mid_num[i];
		
		if (k>=size)
		{
			printf("Invalid mid_num!\n");
			return;
		};
		
		this->order[hash[k]] = char(i+A);
		
		// renew the hash list
		size--;
		for (int i = k; i < size; i++)
			hash[i] = hash[i+1];
	}
	this->order[this->length-1] = pool[hash[0]];
	
	this->altered = false;
}
