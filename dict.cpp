# include <iostream>
# include "pick_list.h"
# include "dict.h"
using namespace std;

bool dict::dict_gen(int* mid_num, char* outstream){
	
	pick_list l(this->size);

	for (int i = 0; i < this->size; i++)
		outstream[i] = l.pop(mid_num[i]);

	return true;
}

bool dict::dict_increase_mid(int* mid_num){

	int p = this->size - 2;
	int r = 1; // increase mid_num
	int step = 2; 

	do{
		mid_num[p] += r;
		r = mid_num[p] / step;
		mid_num[p] %= step;
		p--;
		step++;
	} while ((r > 0) && (p >= 0));
	
	// if over flow
	if (p < 0){
		return false;
	}
	else{
		return true;
	}
}

int main(int argc, char* argv[]){

}