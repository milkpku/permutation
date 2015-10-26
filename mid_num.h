#ifndef MID_NUM
#define MID_NUM

class rank_class
{
protected:
    int length;
    long MAX_RANK;
    long rank;
    bool altered;

    bool valid_rank(long r);     // exam rank number  

public:

    rank_class(int s, long r);
    bool set_rank(long r);
};

class mid_num_in: public rank_class
{
protected:
    int mid_length;        // length of mid_num order
    int* mid_num;          // mid num order

public:
    mid_num_in(int s, long r = 0);

    bool set_mid(long r);
    bool alter(long amount);
};

class mid_num_de: public rank_class
{
protected:
    int mid_length;        // length of mid_num order
    int* mid_num;          // mid num order

public:
    mid_num_de(int s, long r = 0);

    bool set_mid(long r);
    bool alter(long amount);
};


#endif