#ifndef _DEFENCE_PACK_H
#define _DEFENCE_PACK_H

/*    this class is the group of packs that belong to the 'defence' group    */

#include "DefencePack.h"
#include "Sizes.h"
#include "Node.h"
#include "LinkedList.h"
#include "CornerBack.h"
#include "LineBacker.h"
#include "Tackle.h"

#include <cstdlib>
#include <ctime>

class DefenceGroup
{
public:
    DefenceGroup();                                     //c'tor
    DefenceGroup(DefenceGroup &rhs);                //copy c'tor
    ~DefenceGroup();                                     //d'tor
    void operator=(DefenceGroup &rhs);	//copys group by value
	bool setDefenceSize(const int numOfTackle,const int numOfLineBack,const int numOfCornerBack);  //sets number of packs in defence to theSize
    bool setPackLen(const int theLen);  //set's one pack's length to theLen
    Node<DefencePack> *getHead();  //returns pack reference to pack at index i
    void print();                 //prints packs to standrand output stream
    int getDefenceSize() const;         //returns number of packs in defence group
    int getPackLen() const;         //returns pack length 
    int strongestPack() const;      //returns power of strongest pack in group
    void updatePacks();     //half of the packs(the ones with the higher power value) are paired with a random pack from group. then two indexs are randomly chosen and all values between two indexs are swaped respectively
    LinkedList<DefencePack> &getPackList();  //returns pack list
    void orginizeGroupByPower();
private:
    int defenceSize;    //number of packs in defence
    int packLen;        //length of packs
    LinkedList <DefencePack>packs;      //group of packs

    bool isEven(int n);
};


#endif
