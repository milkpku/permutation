#include <iostream>
#include "per_dict.h"
using namespace std;

per_dict::per_dict(int s, long r) : mid_num_in(s, r)
{
	this->order = new char[s];
	this->refresh();	
}

char* per_dict::get_order()
{
	if (this->altered)
	{
		this->refresh();
	};
	
	return this->order;
}

void per_dict::refresh()
{
	const int A = int('a');
	int size = this->length;
	int* hash = new int[size];
	char* pool = new char[size];
	
	// build per_dict
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

bool per_dict::next()
{
	if (!this->alter(1))
	{
		return false;
	}
	
	// find the first decrease one
	int p = this->length - 2;
	while ( this->order[p+1] < this->order[p] )
		p--;
	
	if ( p == this->length - 2 )
	{
		// swap the last two
		int temp;
		temp = this->order[p];
		this->order[p] = this->order[p-1];
		this->order[p-1] = temp;
		this->altered = false;
		return true;
	};
	
	// find next element to replace order[p]
	int start = p, rear = this->length - 1, mid = (start + rear) /2;
	while (start + 1 < rear)
	{
		if (this->order[mid] > this->order[p]){
			start = mid;	
		}else{
			rear = mid - 1;
		};
		
		mid = (start + rear)/2;
	};
	
	if (this->order[rear] < this->order[p])
	{
		rear = rear - 1;
	}
	
	// swap the order[p] and order[rear]
	int temp;
	temp = this->order[p];
	this->order[p] = this->order[rear];
	this->order[rear] = temp;
	
	// swtch the order of order[p:length]
	for(int i = this->length-1; i > (this->length + p)/2; i++)
	{
		temp = this->order[this->length + p - i];
		this->order[this->length + p - i] = this->order[i];
		this->order[i] = temp;
	};
	
	this->altered = false;
	return true;
}