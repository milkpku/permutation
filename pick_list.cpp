#include <iostream>
#include "pick_list.h"
using namespace std;

const int A = int('a');

pick_list::pick_list(int n){    // build a set which contains n character start from 'a'
		// distribute space
		this->size = n - 1;
		this->dict = new char(sizeof(char)*n);
		this->hash = new int(sizeof(int)*n);

		// build dict
		for (int i = 0; i < n; i++)
		{
			hash[i] = i;
			dict[i] = char(i + A);
		};
}

char pick_list::pop(int k){	// pop out the kth min one in the rest set

		if (k>size){
			printf("Exists limit of pick list!\n");
		};

		this->size--;
		char pop_element = dict[hash[k]];
		// renew the hash dict
		for (int i = k; i < size; i++)
			hash[i] += 1;

		return pop_element;
}
