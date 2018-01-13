#ifndef _SIZES_H
#define _SIZES_H
/*   this class is the minimum and maximum values for various variables in ex3   */
class Sizes
{
public:
    static const int MIN_PACK_LEN = 8;
    static const int MAX_PACK_LEN = 10000000;
    
    static const int MIN_ATTACK_SIZE = 1;
    static const int MAX_ATTACK_SIZE = 100;
    
    static const int MIN_DEFENCE_SIZE = 2;
    static const int MAX_DEFENCE_SIZE = 1024;
    
    static const int MIN_CYCLES = 0;
    static const int MAX_CYCLES = 10000000;
};

#endif
