#include <iostream>
#include "decr_permutaion.h"
using namespace std;

decr_permutation::decr_permutation(int s, long r) : mid_num_de(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* decr_permutation::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void decr_permutation::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	char* pool = new char[size];
	
	// build decr_permutation
	for (int i = 0; i < size; i++)
		hash[i] = size - i - 1;
	
	// pop out order
	for(int i=0; i<this->length-1;i++)
	{
		int k = this->mid_num[this->length - i - 1];
		
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
