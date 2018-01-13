#ifndef _PACK_H
#define _PACK_H
/*   this class is a vector of 1 or 0 only   */
#include <iostream>

using namespace std;

class Pack
{
public:
    Pack(const int TheSize); //c'tor
    Pack(const Pack &rhs); //copy c'tor
    virtual ~Pack();                //d'tor
	void operator=(const Pack &rhs);	//copys pack by value
    int getSize() const;        //returns size of pack
    int& operator[](const int index); //returns index in bin
    int operator[](const int index) const;
    void print() const;     //prints bin to standard input stream
    virtual string toString();
private:
    int size;       //size of pack
    int *bin;       //holds 'size' amount of binary numbers

};


#endif
