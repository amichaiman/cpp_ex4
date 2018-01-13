#include "LineBacker.h"


LineBacker::LineBacker(const int theSize)
try:DefencePack(theSize)
{}
catch (exception &e){
    throw e;
}
LineBacker::LineBacker(const LineBacker &rhs)
try:DefencePack(rhs)
{}

catch (exception &e){
    throw e;
}

LineBacker::~LineBacker()
{}

void LineBacker::operator=(const LineBacker &rhs)
{
	DefencePack::operator=(rhs);
}

void LineBacker::earlyUpdate()
{}


string LineBacker::toString()
{
    return DefencePack::toString()+" L";
}
