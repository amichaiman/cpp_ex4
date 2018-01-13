#ifndef _LINEBACKER_H
#define _LINEBACKER_H

#include "DefencePack.h"

class LineBacker : public DefencePack
{
public:
    LineBacker(const int theSize);	//c'tor
    LineBacker(const LineBacker &rhs);	//copy c'tor
    ~LineBacker();						//d'tor
	void operator=(const LineBacker &rhs);	//copys pack by value
    virtual void earlyUpdate();			//flips bits in a properbility of 0%
    string toString();
};

#endif
