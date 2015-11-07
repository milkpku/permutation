#include <iostream>
#include "mid_num.h"

using namespace std;

////////////////////////////// function of class rank 
long fact(int s){
    if (s<3){
        return s;
    }
    else{
        return s*fact(s-1);
    };
};

rank_class::rank_class(int s, long r){
    this->length = s;
    MAX_RANK = fact(s);
    set_rank(r);
};

bool rank_class::valid_rank(long r){
    if (r >= this->MAX_RANK){
        printf("Invalid input r! It is too large.\n");
        return false;
    };
    if (r < 0){
        printf("Invalid input r! It is negetive.\n");
        return false;
    };

    return true;
};

bool rank_class::set_rank(long r){
    // judge if r is valid
    if (!valid_rank(r)){
        printf("Failed when setting rank!\n");
        return false;
    };

    this->rank = r;
    this->altered = true;
    return true;
};

///////////////////////////////////////////// function of mid_num_in
mid_num_in::mid_num_in(int s, long r):rank_class(s,r)
{
    this->mid_length = s-1;
    this->mid_num = new int[mid_length];
    
    if (!this->set_mid(r)){
        printf("Failed when instance mid_num_in!\n");
    }
};

bool mid_num_in::set_mid(long r){
    // judge if r is valid
    if (!this->set_rank(r)){
        return false;
    };

    // rank to mid_num procedure
    for (int i = 2; i<length+1; i++){
        mid_num[length - i] = r % i;
        r /= i;
    };

    return true;
}

bool mid_num_in::alter(long amount){
    if (!this->set_rank(this->rank+amount)){
        printf("Failed when changing mid_num_in!\n");
        return false;
    };

    // rank to mid_num procedure
    int p = mid_length-1;
    do{
        mid_num[p] += amount;
        amount = mid_num[p] / (length - p);
        mid_num[p] %= (length - p);
        p--;
    } while (amount!=0);

    return true;
}

/////////////////////////////////////////////// function of mid_num_de
mid_num_de::mid_num_de(int s, long r):rank_class(s,r)
{
    this->mid_length = s-1;
    this->mid_num = new int[mid_length];
    
    if (!this->set_mid(r)){
        printf("Failed when instance mid_num_de!\n");
    }
};

bool mid_num_de::set_mid(long r){
    // judge if r is valid
    if (!this->set_rank(r)){
        return false;
    };

    // rank to mid_num procedure
    for (int i = length; i>1; i--){
        mid_num[i-2] = r % i;
        r /= i;
    };

    return true;
}

bool mid_num_de::alter(long amount){
    if (!this->set_rank(rank+amount)){
        printf("Failed when changing mid_num_de!\n");
        return false;
    };

    // rank to mid_num procedure
    int p = mid_length-1;
    do{
        mid_num[p] += amount;
        amount = mid_num[p] / (p + 2);
        mid_num[p] %= (p + 2);
        p--;
    } while (amount!=0);

    return true;
}