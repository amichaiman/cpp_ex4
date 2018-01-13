#ifndef _WAR_ZONE_H
#define _WAR_ZONE_H


/*   this class is where interactions between offence packs and defence packs take place   */


#include "Pack.h"
#include "DefencePack.h"
#include "AttackGroup.h"
#include "DefenceGroup.h"

class WarZone
{
public:
    WarZone(); //c'tor
    ~WarZone(); //d'tor
    WarZone(const WarZone &rhs); //copy c'tor
    void operator=(const WarZone &rhs);	
	int checkPower(const Pack &offence, const DefencePack &defence) const; //returns number of matching values between the two packs
    void findMaxPower(const AttackGroup &attackGroup, DefencePack &p); //finds wich of the packs in the attack group has most matching values with given defence pack
    void checkDefencePower(const AttackGroup &attackGroup, DefenceGroup &defenceGroup); //checks each one of the packs in the defence group against all packs in attack group, and sets their power accordingly
private:
    
};
#endif
