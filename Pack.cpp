#include "Pack.h"

Pack::Pack(const int theSize)
try:size(theSize),bin(new int[theSize])
{}
catch(exception &e){
    throw e;
}


Pack::~Pack()
{
    delete(bin);
}

Pack::Pack(const Pack &rhs)
try: size(rhs.getSize()),bin(new int[size]) 
{
    for (int i=0; i<size; i++)
        bin[i] = rhs[i];
}
catch (exception &e){
    throw e;
}

void Pack::operator=(const Pack &rhs)
{
	if (size != rhs.getSize())
	{
		delete(bin);
		bin = new int[rhs.getSize()];
	}
	
	for (int i=0; i<size; i++)
		bin[i] = rhs[i];
}

int Pack::getSize() const
{
    return size;
}

int& Pack::operator[](const int index)
{
    return bin[index];
}


int Pack::operator[](const int index) const
{
    return bin[index];
}

void Pack::print() const
{
    for (int i=0; i<size; i++)
        cout << bin[i] << " ";
    cout << endl;
}

string Pack::toString()
{
    string s = "";

    for (int i=0; i<size; i++)
    {
        s += bin[i]+'0';
        s += " ";
    }
    return s;
}
