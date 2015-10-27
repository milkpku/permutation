#include <iostream>
#include "pick_list.h"
#include "dict.h"
using namespace std;

dict::dict(int s, long r) : mid_num_in(s, r)
{
	this->order = new char[s];
	this->refreshed = false;
	this->refresh();	
}

void dict::refresh()
{
	pick_list pool(this->length);
	
	for(int i=0;i<this->length-1;i++)
		this->order[i] = pool.pop(mid_num[i]);
		
	this->order[this->length-1] = pool.pop(0);
	
	this->altered = false;
}

char* dict::get_order()
{
	if (this->altered){
		this->refresh();
	};
	
	return this->order;
}