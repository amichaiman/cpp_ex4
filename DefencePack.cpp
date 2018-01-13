#include "DefencePack.h"


DefencePack::DefencePack(const int theSize)
try:Pack(theSize),power(0)
{
    for (int i=0; i<getSize(); i++)
        operator[](i) = rand()%2;
}
catch(exception &e){
    throw e;
}

DefencePack::~DefencePack()
{}

void DefencePack::operator=(const DefencePack &rhs)
{
	power = rhs.getPower();
	Pack::operator=(rhs);
}
DefencePack::DefencePack(const DefencePack &rhs)
try:Pack(rhs), power(rhs.getPower())
{}

catch(exception &e){
    throw e;
}

int DefencePack::getPower() const 
{
    return power;
}

void DefencePack::setPower(const int thePower)
{
    power = thePower;    
}

bool DefencePack::operator>(const DefencePack &rhs)
{
    return power > rhs.getPower();
}
bool DefencePack::operator==(const DefencePack &rhs)
{
    return power == rhs.getPower();
}

bool DefencePack::operator<(const DefencePack &rhs)
{
    return power < rhs.getPower();
}
void DefencePack::operator%(DefencePack &rhs)
{
    int firstCut = rand()%getSize();    //firstCut gets random index between packs range
    int secondCut = rand()%getSize();   //secondCut gets random index between packs range
    int temp;   //used for swap
    
    while (firstCut == secondCut)   //make sure indexs are different
        secondCut = rand()%getSize();
    
    if (secondCut < firstCut) //make sure fistCut is the smaller index
    {
        temp = firstCut;
        firstCut = secondCut;
        secondCut = temp;
    }
    
    for (int i=firstCut; i<=secondCut; i++)
    {
        temp = operator[](i);
        operator[](i) = rhs[i];
        rhs[i] = temp;
    }
}
void DefencePack::earlyUpdate()
{}

