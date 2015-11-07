#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

void print_char(int length, char* order)
{
	for(int i =0; i<length; i++)
		printf("%c ", order[i]);
	printf("\n");
};

long factorial(int n)
{
	long result = 1;
	do{
		result *= n;
		n = n-1;
	} while(n>1);
	 
	return result;
}

void dict_perm(int n){
// initialize
	int size = n;
	long MAX_PER = factorial(n);
	const int A = (int) 'a';

	char* order = malloc(size * sizeof(char)); 
	
	int move_p;					// move_p is the element to be replaced
	int next_p; 				// next_p is the element to replace
	int loop;
	char temp_char;
	
	for(int i = 0; i< size; i++)
		order[i] = (char)(i + A);

// generating
	// print_char(size, order);
	
	for(long r = 1; r<MAX_PER; r++)
	{
		move_p = size - 2;
		next_p = size - 1;
		if (order[move_p]<order[next_p])
		{
			temp_char = order[next_p];
			order[next_p] = order[move_p];
			order[move_p] = temp_char;
		}else{
			do{
				move_p--;
			} while (order[move_p]>order[move_p + 1]);
			// find the next one 
			while(order[next_p]<order[move_p])
				next_p--;
			// switch the two
			temp_char = order[next_p];
			order[next_p] = order[move_p];
			order[move_p] = temp_char;
			// convert the line
			for(loop=(move_p+size-1)/2; loop>move_p;loop--)
			{
				temp_char = order[loop];
				order[loop] = order[move_p + size - loop];
				order[move_p + size - loop] = temp_char;
			};
		}
	  // print_char(size, order);
	};
}


void adj_perm(int n){
// initialize
	int size = n;
	long MAX_PER = factorial(n);
	const int A = (int) 'a';
	
	int* hash = malloc(size * sizeof(int));      // hash[i] is location of ith element 
	int* direction = malloc(size * sizeof(int)); // direction[i] is the direction of ith max element: 1 left, -1 right

	char* order = malloc((size+2) * sizeof(char));  // add two Sentinels
	
	int loc_a, loc_b; 					// switch area
	char temp_char;
	int move_p;									// move_p is the largest mobile element
	
	for(int i = 0; i< size; i++)
	{
		direction[i] = 1;
		hash[i] = i+1;
	};

	for (int i = 0; i < size + 2; i++)
		order[(i + 1) % (size+2)] = (char)(i + A);

// generating
	// print_char(size, order);
	
	for(long r = 1; r<MAX_PER; r++)
	{
		// find the largest mobile element
		move_p = size-1;
		while (order[hash[move_p] - direction[move_p]] > order[hash[move_p]])
		{
			direction[move_p] = -direction[move_p];   // reverse direction
			move_p--;
		} 
		
		// switch
		loc_a = hash[move_p]; loc_b = loc_a -direction[move_p];
		temp_char = order[loc_a];
		order[loc_a] = order[loc_b];
		order[loc_b] = temp_char;
		// update hash
		hash[move_p] -= direction[move_p];
		hash[(int)order[loc_a]-A] += direction[move_p];
		  
		// print result
		// print_char(size, order);
	};
}

void dict_perm_new(int n){

// initialize
	int size = n;
	long MAX_PER = factorial(n);
	const int A = (int) 'a';

	char* order = malloc(size * sizeof(char)); 
	
	int move_p;					// move_p is the element to be replaced
	int next_p; 				// next_p is the element to replace
	int loop;
	char temp_char;
	
	for(int i = 0; i< size; i++)
		order[i] = (char)(i + A);

// generating
	// print_char(size, order);
	
	for(long r = 1; r<MAX_PER; r++)
	{
		move_p = size - 2;
		next_p = size - 1;
		if (order[move_p]<order[next_p])
		{
			temp_char = order[next_p];
			order[next_p] = order[move_p];
			order[move_p] = temp_char;
		}else{
			do{
				move_p--;
			} while (order[move_p]>order[move_p + 1]);
			
			if (move_p == size - 3)
			{
				if (order[move_p]<order[next_p]){
					temp_char = order[next_p];
					order[next_p] = order[move_p+1];
					order[move_p+1] = order[move_p];
					order[move_p] = temp_char;
				}else{
					temp_char = order[next_p];
					order[next_p] = order[move_p];
					order[move_p] = order[move_p+1];
					order[move_p+1] = temp_char;
				};
			}else{
				// find the next one 
				while(order[next_p]<order[move_p])
					next_p--;
				// switch the two
				temp_char = order[next_p];
				order[next_p] = order[move_p];
				order[move_p] = temp_char;
				// convert the line
				for(loop=(move_p+size-1)/2; loop>move_p;loop--)
				{
					temp_char = order[loop];
					order[loop] = order[move_p+size-loop];
					order[move_p+size-loop] = temp_char;
				};
			}
		}
	  // print_char(size, order);
	};
}

void gen_heap_perm(int size, int n, char *order)
{
	int c;
	char temp;
	if(n == 1){
		//print_char(size, order);
	}
	else{
		for(c = 0; c < n; c++){
			gen_heap_perm(size, n - 1, order);
			if(n % 2 == 1){
				temp = order[n - 1];
				order[n - 1] = order[0];
				order[0] = temp;
			}
			else{
				temp = order[n - 1];
				order[n - 1] = order[c];
				order[c] = temp;
			}
		}
	}
}

void heap_perm(int n){
	//initialize
	int size = n;
	long MAX_PER = factorial(n);
	const int A = (int) 'a';

	char* order = malloc(size * sizeof(char)); 

	for(int i = 0; i< size; i++)
		order[i] = (char)(i + A);

	gen_heap_perm(size, size, order);
}
