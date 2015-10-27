#include <iostream>
#include "pick_list.h"
using namespace std;

const int A = int('a');

pick_list::pick_list(int n){    // build a set which contains n character start from 'a'
	// distribute space
	this->size = n;
	this->dict = new char[n];
	this->hash = new int[n];

	// build dict
	for (int i = 0; i < n; i++)
	{
		hash[i] = i;
		dict[i] = char(i + A);
	};
}

pick_list::~pick_list(){
	printf("pick_list deleted.");
	delete [] this->dict;
	
	printf("pick_list deleted.");
	delete [] this->hash;
	
	printf("pick_list deleted.");
}

char pick_list::pop(int k){	// pop out the kth min one in the rest set

	if (k>=size){
		printf("Exists limit of pick list!\n");
	};

	this->size--;
	char pop_element = dict[hash[k]];
	// renew the hash dict
	for (int i = k; i < size; i++)
		hash[i] = hash[i+1];

	return pop_element;
}
