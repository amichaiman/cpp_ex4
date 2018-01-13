#include "WarZone.h"

WarZone::WarZone(){}
WarZone::~WarZone(){}
WarZone::WarZone(const WarZone &rhs){}
void WarZone::operator=(const WarZone &rhs){}
int WarZone::checkPower(const Pack &offence, const DefencePack &defence) const
{
    int power = 0;
    
    for (int i=0; i<offence.getSize();i++)
        if (offence[i] == defence[i])
            power++;
    return power;
}

void WarZone::findMaxPower(const AttackGroup &attackGroup, DefencePack &p)
{
    int cur_power;
    int max_power = 0;
    
    for (int i=0; i<attackGroup.getAttackSize(); i++)
    {
        cur_power = checkPower(attackGroup.getPack(i),p);
        if (cur_power > max_power)
            max_power = cur_power;
    }
    p.setPower(max_power);
}

void WarZone::checkDefencePower(const AttackGroup &attackGroup, DefenceGroup &defenceGroup)
{
    Node<DefencePack> *cur= defenceGroup.getHead();

    while(cur != NULL)
    {
        findMaxPower(attackGroup,*(cur->getKey()));
        cur = cur->getNext();
    }
}