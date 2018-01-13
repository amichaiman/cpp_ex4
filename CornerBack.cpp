#include "CornerBack.h"

CornerBack::CornerBack(const int theSize)
try:DefencePack(theSize),properbilityForFlip(1.0/getSize())
{}
catch(exception &e){
    throw e;
}

CornerBack::CornerBack(const CornerBack &rhs)
try:DefencePack(rhs)
{}

catch (exception &e){
    throw e;
}

CornerBack::~CornerBack(){}

void CornerBack::operator=(const CornerBack &rhs)
{
	DefencePack::operator=(rhs);
}

void CornerBack::earlyUpdate()
{
    for (int i=0; i<getSize(); i++)
    {
        if (flip() == true)
        {
            if (operator[](i) == 1)
                operator[](i) = 0;
            else
                operator[](i) = 1;
        }
    }
}

bool CornerBack::flip()
{
    return (double)rand()/RAND_MAX <  properbilityForFlip;
}


string CornerBack::toString()
{
    return DefencePack::toString()+" C";
}
