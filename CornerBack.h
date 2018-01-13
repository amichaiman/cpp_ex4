#ifndef _CORNERBACK_H
#define _CORNERBACK_H

#include "DefencePack.h"

class CornerBack : public DefencePack
{
public:
    CornerBack(const int theSize);	//c'tor
    CornerBack(const CornerBack &rhs);	//copy c'tor
    ~CornerBack();						//d'tor
	void operator=(const CornerBack &rhs); //copys pack by value
    virtual void earlyUpdate();	//flips bits in a properbility of (1/size)%
    string toString();
private:
    bool flip();
    int properbilityForFlip;
};
#endif