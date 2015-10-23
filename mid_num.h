#ifndef MID_NUM
#define MID_NUM

class mid_num_in{
protected:
    int mid_length;        // length of mid_num order
    int length;            // length of whole order, length = mid_length + 1
    long MAX_RANK;         // max rank of the order can acheave
    long rank;             // current rank 
    int* mid_num;          // mid num order

    // void rank_to_mid();    // convert rank to mid_num order
    // void mid_to_rank();    // convert mid_num order to rank

    // bool valid_rank(long r);     // exam rank number  
    // bool valid_mid_num();  // exam mid_num number

public:
    mid_num_in(int s, int r = 0);
    // mid_num_in(int s, int* order);

    bool set_rank(int r);
    // bool set_mid_num(int* order);
    bool alter(int amount);
};

class mid_num_de{
};


#endif