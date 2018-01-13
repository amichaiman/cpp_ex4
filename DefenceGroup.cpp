#include "DefenceGroup.h"


DefenceGroup::DefenceGroup()
{}

DefenceGroup::DefenceGroup(DefenceGroup &rhs)
{
    packs = rhs.getPackList();
}

DefenceGroup::~DefenceGroup()
{
    packs.clear();
}

void DefenceGroup::operator=(DefenceGroup &rhs)
{
	defenceSize = rhs.getDefenceSize();
	packLen = rhs.getPackLen();
	packs = rhs.getPackList();
}
LinkedList<DefencePack> &DefenceGroup::getPackList()
{
    return packs;
}

bool DefenceGroup::setPackLen(const int theLen)
{
    packLen = theLen;
    if (packLen < Sizes::MIN_PACK_LEN || packLen > Sizes::MAX_PACK_LEN)
        return false;
    return true;
}

bool DefenceGroup::setDefenceSize(const int numOfTackle,const int numOfLineBack,const int numOfCornerBack)
{
    defenceSize = numOfTackle+numOfLineBack+numOfCornerBack;
    
    if (numOfTackle+numOfLineBack+numOfCornerBack < Sizes::MIN_DEFENCE_SIZE || numOfTackle+numOfLineBack+numOfCornerBack > Sizes::MAX_DEFENCE_SIZE || !isEven(defenceSize))
        return false;
    
    try{
        /*  add packs to group according to input   */    
        for (int i=0; i<numOfTackle; i++)
            packs.insert(new Node<DefencePack>(new Tackle(packLen)));
        
        for (int i=0; i<numOfCornerBack; i++)
            packs.insert(new Node<DefencePack>(new CornerBack(packLen)));
        
        for (int i=0; i<numOfLineBack; i++)
            packs.insert(new Node<DefencePack>(new LineBacker(packLen)));
    } catch (exception &e){
        throw e;
    }
    return true;
}


void DefenceGroup::print()
{
    packs.print();
}



Node<DefencePack> *DefenceGroup::getHead()
{
    return packs.getHead();
}

int DefenceGroup:: getDefenceSize() const
{
    return packs.getSize();
}


int DefenceGroup::strongestPack() const
{
    return packs.first()->getPower();

}


void DefenceGroup::updatePacks()
{
    Node<DefencePack> *cur = packs.getHead();
    
    while (cur != NULL)
    {
        cur->getKey()->earlyUpdate();       
        cur = cur->getNext();
    }
    cur = packs.getHead();
    
    for (int i=0; i<packs.getSize()/2; i++)
    {
        *(cur->getKey())%(*(packs.getRandomNode()->getKey()));
		cur = cur->getNext(); 
    }
}

int DefenceGroup::getPackLen() const
{
    return packLen;
}

bool DefenceGroup::isEven(int n)
{
    return n%2==0 ? 1 : 0;
}

void DefenceGroup::orginizeGroupByPower()
{
    packs.reOrginize();
}
