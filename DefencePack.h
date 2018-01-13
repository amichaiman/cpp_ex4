#ifndef _DPACK_H
#define _DPACK_H

#include "Pack.h"

#include <cstdlib>
#include <ctime>

/*   this class is for packs used by defence group.
     DefencePack differs from Pack by having a power field as well*/
class DefencePack : public Pack
{
public:
    DefencePack(const int theSize);   //c'tor
    virtual ~DefencePack() = 0;                   //d'tor
    DefencePack(const DefencePack &rhs);    //copy c'tor
	void operator=(const DefencePack &rhs);	//copys group by value
    virtual void earlyUpdate();
    int getPower() const;       //return power 
    void setPower(const int thePower);  //sets power
    bool operator>(const DefencePack &rhs);   //returns true if power is bigger than rhs's power. false otherwise
    bool operator<(const DefencePack &rhs); //returns true if pwoer is smaller than rhs's power. false otherwise
    bool operator==(const DefencePack &rhs); //returns true if power of rhs is equal. false otherwise.
    void operator%(DefencePack &rhs); //swaps all values within two random indexs between rhs, and "this" 
private:
    int power;  //number wich represents packs strength 
};

#endif
