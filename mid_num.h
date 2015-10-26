#ifndef MID_NUM
#define MID_NUM

class rank
{
protected:
    int length;
    long MAX_RANK;
    long rank;

    bool valid_rank(long r);     // exam rank number  

public:

    rank(int s, long r);
    bool set_rank(long r);
};

class mid_num_in: public rank
{
protected:
    int mid_length;        // length of mid_num order
    int* mid_num;          // mid num order

public:
    mid_num_in(int s, int r = 0);
    // mid_num_in(int s, int* order);

    bool set_mid(int r);
    // bool set_mid_num(int* order);
    bool alter(int amount);
};

class mid_num_de: public rank
{
};


#endif