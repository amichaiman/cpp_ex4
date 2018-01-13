#ifndef _NODE_H
#define _NODE_H

#include <iostream> //for debugging
using namespace std;    //for debugging



template <class T>
class Node{
public:
    Node();				//c'tor
    Node(T *theKey);		//c'tor
    Node(const Node &rhs);	//copy c'tor
    ~Node();				//d'tor
	void operator=(const Node &rhs); // copys KEY ONLY by value
    void setNext(Node *n);		//sets next node to n
    Node *getNext() const;			//returns next node pointed at by current
    void setPrev(Node *p);		//sets previous node to n
    Node *getPrev() const;		//returns previous node pointed at by current
    void setKey(const T *theKey);		//key's setter
    T *getKey() const;					//key's getter
    bool hasNext() const;			//returns true if current node has next, false otherwise
    bool operator==(const Node &rhs);		//returns true if nodes key's are equal, false otherwise
private:
    T *key;
    Node <T>*next;
    Node <T>*prev;
};

/*   T's key must implement operator== as well   */
template <class T>
bool Node<T>::operator==(const Node<T> &rhs)
{
    return key == rhs.getKey();
}


template <class T>
void Node<T>::operator=(const Node<T> &rhs)
{
	*key = *(rhs.getKey());
}


template <class T>
bool Node<T>::hasNext() const
{
    return next != NULL;
}

template <class T>
Node<T>::Node(T *theKey)
:key(theKey),next(NULL),prev(NULL)
{}

template <class T>
Node<T>::Node()
:key(NULL),next(NULL),prev(NULL)
{}

template <class T>
Node<T>::Node(const Node &rhs)
{
    key = rhs.getKey();
    next = rhs.getNext();
    prev = rhs.getPrev();
}


template <class T>
Node<T>::~Node()
{}


template <class T>
void Node<T>:: setNext(Node *n)
{
    next = n;
}


template <class T>
Node<T> *Node<T>::getNext() const
{
    return next;
}

template <class T>
void Node<T>::setPrev(Node *p)
{
    prev = p;
}

template <class T>
Node<T> *Node<T>::getPrev() const
{
    return prev;
}

template <class T>
void Node<T>::setKey(const T *theKey)
{
    key = theKey;
}


template <class T>
T *Node<T>::getKey() const
{
    return key;
}

#endif