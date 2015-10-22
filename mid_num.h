#ifndef MID_NUM
#define MID_NUM

class mid_num_in{
private:
    int length;		       // length of mid_num order
    long MAX_RANK;	       // max rank of the order can acheave
    long rank;		       // current rank 
    int* mid_num;          // mid num order

    void rank_to_mid();    // convert rank to mid_num order
    void mid_to_rank();    // convert mid_num order to rank

    bool valid_rank();  
    bool valid_mid_num();

public:
    mid_num_in(int s, int r = 0);
    mid_num_in(int s, int* order);

    bool set_rank(int r);
    bool set_mid_num(int* order);+
    bool alter(int amount);
};

class mid_num_de{
private:
    int length;
    long MAX_RANK;
    long rank;
    int* mid_num;

    void rank_to_mid();
    void mid_to_rank();

    bool valid_rank();
    bool valid_mid_num();

public:
    mid_num_de(int s, int r = 0);
    mid_num_de(int s, int* order);

    bool set_rank(int r);
    bool set_mid_num(int* order);
    bool alter(int amount);
};


#endif