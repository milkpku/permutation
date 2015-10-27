#include <iostream>
#include "per_cantor.h"
using namespace std;

per_cantor::per_cantor(int s, long r) : mid_num_in(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* per_cantor::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void per_cantor::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	
	// build per_cantor
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
