#ifndef MID_NUM
#define MID_NUM

long fact(int s);

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
    
    ///////////////////////////////////////////////// for test
    long rank_max(){return this->MAX_RANK;};                        // test_code
    long rank_rank(){return this->rank;};                           // test_code
    bool rank_altered(){return this->altered;};                     // test_code
    ///////////////////////////////////////////////// for test
    
};

class mid_num_in: public rank_class
{
protected:
    int mid_length;        // length of mid_num order
    int* mid_num;          // mid num order

public:
    mid_num_in(int s, long r = 0);
    ~mid_num_in(){delete [] mid_num;};

    bool set_mid(long r);
    bool alter(long amount);
    
    ///////////////////////////////////////////////// for test
    int* get_mid_num(){return this->mid_num;};                        // test_code
    ///////////////////////////////////////////////// for test
    
};

class mid_num_de: public rank_class
{
protected:
    int mid_length;        // length of mid_num order
    int* mid_num;          // mid num order

public:
    mid_num_de(int s, long r = 0);
    ~mid_num_de(){delete [] mid_num;};
    
    bool set_mid(long r);
    bool alter(long amount);
    
    ///////////////////////////////////////////////// for test
    int* get_mid_num(){return this->mid_num;};                        // test_code
    ///////////////////////////////////////////////// for test
    
};


#endif