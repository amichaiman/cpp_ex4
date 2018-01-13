#include "Tackle.h"

Tackle::Tackle(const int theSize)
try:DefencePack(theSize)
{}
catch(exception &e){
    throw e;
}
Tackle::Tackle(const Tackle &rhs)
try:DefencePack(rhs)
{}

catch (exception &e){
    throw e;
}

Tackle::~Tackle(){}

void Tackle::operator=(const Tackle &rhs)
{
	DefencePack::operator=(rhs);
}
void Tackle::earlyUpdate()
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

bool Tackle::flip()
{
    return (double)rand()/RAND_MAX <  properbilityForFlip;
}

ostream &operator<<(ostream &out, Tackle &t)
{
    cout << t << " " << "T" << endl;
    return out;
}



string Tackle::toString()
{
    return DefencePack::toString()+" T";
}
