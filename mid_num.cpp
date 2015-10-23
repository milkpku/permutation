#include <iostream>
#include "mid_num.h"

using namespace std;

long fact(int s){
    if (s<3){
        return s;
    }
    else{
        return s*fact(s-1);
    };
};

mid_num_in::mid_num_in(int s, int r){
    this->length = s;
    this->mid_length = s-1;
    MAX_RANK = fact(s);
    this.mid_num = new int[mid_length];
    
    if !this->set_rank(r){
        printf("Failed when instance mid_num_in!\n");
    }
};

mid_num_in::set_rank(int r){
    // judge if r is valid
    if (!valid_rank(r)){
        printf('Failed when setting rank!\n');
        return false;
    };

    // rank to mid_num procedure
    this->rank = r;
    for (int i = 2; i<length+1; i++){
        mid_num[length - i] = r % i;
        r /= i;
    };

    return true;
}

mid_num_in::valid_rank(long r){
    if (r>this->MAX_RANK)or(r<0){
        printf('Invalid input r!\n');
        return false;
    };
    return true;
};

bool alter(int amount){
    if (!valid_rank(rank+amount)){
        printf("Alter too large!\n");
        return false;
    };

    this->rank = r + amount;
    // rank to mid_num procedure
    int p = mid_length-1;
    do{
        mid_num[p] += amount;
        amount = mid_num[p] / (length - p);
        mid_num[p] %= (length - p);
    } while (amount!=0);

    return true;
}