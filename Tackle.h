#ifndef _TACKLE_H
#define _TACKLE_H

#include "DefencePack.h"

class Tackle : public DefencePack
{
public:
    Tackle(const int theSize);	//c'tor
    Tackle(const Tackle &rhs);	//copy c'tor
    ~Tackle();						//d'tor
	void operator=(const Tackle &rhs); //copys pack by value
    virtual void earlyUpdate();		//flips bits in a properbility of 25%
    string toString();			
private:
    bool flip();
    static const int properbilityForFlip = 0.25;
};
#endif