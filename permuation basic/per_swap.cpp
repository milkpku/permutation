#include <iostream>
#include "per_swap.h"
using namespace std;

per_swap::per_swap(int s, long r) : mid_num_de(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* per_swap::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void per_swap::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	
	// build per_swap
	for (int i = 0; i < size; i++)
		hash[i] = i;
	
	// pop out order
	int direction, k;
	for(int i=this->mid_length-1; i>0; i--)
	{
		// decide direction
		if (i%2 == 0){
			direction = (mid_num[i-2]+mid_num[i-1]) % 2;
		}else{
			direction = mid_num[i-1] % 2;
		};
		
		// the location from left to count
		if (direction == 1){
			k = this->mid_num[i];
		}else{
			k = size - 1 - this->mid_num[i];
		};
		
		if ((k>=size)||(k<0))
		{
			printf("Invalid mid_num!\n");
			return;
		};
		
		this->order[hash[k]] = char(i+1 + A);
		
		// renew the hash list
		size--;
		for (int j = k; j < size; j++)
			hash[j] = hash[j+1];
	}
	
	if (mid_num[0] == 0)
	{
		this->order[hash[0]] = char(A);
		this->order[hash[1]] = char(A+1);
	}else{
		this->order[hash[1]] = char(A);
		this->order[hash[0]] = char(A+1);
	}
	
	this->altered = false;
}
