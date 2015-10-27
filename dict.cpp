#include <iostream>
#include "dict.h"
using namespace std;

dict::dict(int s, long r) : mid_num_in(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* dict::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void dict::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	char* pool = new char[size];
	
	// build dict
	for (int i = 0; i < size; i++)
	{
		hash[i] = i;
		pool[i] = char(i + A);
	};
	
	// pop out order
	for(int i=0; i<this->length-1;i++)
	{
		int k = this->mid_num[i];
		
		if (k>=size){
			printf("Invalid mid_num!\n");
			return;
		};
		
		this->order[i] = pool[hash[k]];
		
		// renew the hash list
		size--;
		for (int i = k; i < size; i++)
			hash[i] = hash[i+1];
	}
	this->order[this->length-1] = pool[hash[0]];
	
	this->altered = false;
}
