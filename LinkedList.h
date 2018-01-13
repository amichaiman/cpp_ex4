#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream> 
#include "DefencePack.h"
#include <cstdlib>
#include <ctime>

using namespace std;  

/*	class is generic linked list. 
	list is orginized by the value of the keys
	in nodes. (from higher to lower) 	*/
	
template <class T>
class LinkedList{
public:
    LinkedList();			//c'tor
    LinkedList(Node<T> *head);		//c'tor
    LinkedList(const LinkedList &rhs);	//copy c'tor
    ~LinkedList();						//d'tor
	void operator=(const LinkedList &rhs); //copys list by value
    void setHead(const Node<T> *head);	//head's setter
    Node<T> *getHead() const;			//head's getter
    void setTail(const Node<T> *tail);	//tail's setter
    Node<T> *getTail() const;			//tail's getter
    void setSize(const int theSize);	//size setter
    int getSize() const;				//size getter
    LinkedList<T> operator++(int);		//increments linked list's size. 
    LinkedList<T> operator++();			//increments linked list's size. 
    void insert(Node<T> *toInsert);		//inserts node to currect spot 
    T *first() const;					//returns key in head
    T *last() const;					//returns key in tail
    Node<T> *findForward(const Node<T> *toFind) const;	//returns node which contains same key as toFind's. starting from beginning
    Node<T> *findBackward(const Node<T> *toFind) const;	//returns node which contains same key as toFind's. starting from end
    void erase(Node<T> *toErase);	//removes all nodes containing keys which are equal to toErases's key
    void clear();					//removes all nodes in list
    void print();					//prints all key's in list
    Node<T> *getRandomNode();		//returns a random node from list
    void reOrginize();				//reorginizes list from highest to lowest
private:
    Node <T>*head;
    Node <T>*tail;
    int size;
    void removeFromList(Node<T> *toRemove);	// removes toRemove from list
};

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
	clear();
	
	for (int i=0; i<rhs.getSize(); i++)
		insert(new Node<T>());
	
	Node<T> *curInRhs = rhs.getHead();
	Node<T> *cur = head;
	
	while (cur != NULL)
	{
		*cur = *curInRhs;
		cur = cur->getNext();
		curInRhs = curInRhs->getNext();
	}
}

template <class T>
void LinkedList<T>::reOrginize()
{
    if (head == NULL)
        return;

    Node<T> *cur = head;
    Node<T> *next = head->getNext();
    
    head = NULL;
    tail = NULL;
    size = 0;

    while (next != NULL)
    {
        insert(cur);
        cur = next;
        next = next->getNext();
    }
    insert(cur);
}

template <class T>
void LinkedList<T>::print()
{
    cout << *this << endl;
}

template <class T>
void LinkedList<T>::clear()
{
    if (head == NULL)
        return;

    removeFromList(head);
    size--;
    clear();
}
template <class T>
void LinkedList<T>::erase(Node<T> *toErase)
{
    Node<T> *toDelete;
    
    toDelete = findForward(toErase);
    
    while (toDelete != NULL && toErase->getKey() == toDelete->getKey())
    {
        toErase = toDelete->getNext(); 
        removeFromList(toDelete);
        size--;
        toDelete = toErase;
    }
}
template <class T>
void LinkedList<T>::removeFromList(Node<T> *toRemove)
{
    Node<T> *temp;
    
    if (toRemove == head)
    {
        temp = head;
        head = head->getNext();
        
        if (head != NULL)
            head->setPrev(NULL);
        delete(temp);
        return;
    }

    if (toRemove == tail)
    {
        temp = tail;
        tail = tail->getPrev();
        tail->setNext(NULL);
        delete(temp);
        return;
    }
    
    toRemove->getPrev()->setNext(toRemove->getNext());
    toRemove->getNext()->setPrev(toRemove->getPrev());
    
    delete toRemove; 
}
template <class T>
Node<T> *LinkedList<T>::findForward(const Node<T> *toFind) const
{
    Node<T> *cur = head;

    while (cur != NULL)
    {
        if ((*cur->getKey()) == *(toFind->getKey()))
            return cur;
        
        cur = cur->getNext();
    }
    return NULL;
}

template <class T>
Node<T> *LinkedList<T>::findBackward(const Node<T> *toFind) const
{
    Node<T> *cur = tail;

    while (cur != NULL)
    {
        if ((*cur->getKey()) == *(toFind->getKey()))
            return cur;
        cur = cur->getPrev();
    }

    return NULL;
}

template <class T>
void LinkedList<T>::insert(Node<T> *toInsert)
{
    toInsert->setNext(NULL);
    toInsert->setPrev(NULL);
    size++;

    if (!head)  //list is empty
    {
        head = toInsert;
        tail = toInsert;
        return;
    }

    if (*(head->getKey()) < *(toInsert->getKey()))    //toInsert is bigger than head
    {
        head->setPrev(toInsert);
        toInsert->setNext(head);
        head = toInsert;

        return;
    }

    Node<T> *cur = head;
    
    while (cur->hasNext())                      //find correct spot
    {
        if (*(cur->getNext()->getKey()) > *(toInsert->getKey()))  //toInsert is smaller than next node
            cur = cur->getNext();
        else
        {
            toInsert->setNext(cur->getNext());
            toInsert->setPrev(cur);
            cur->setNext(toInsert);
            return;
        }
    }
    toInsert->setPrev(cur);
    cur->setNext(toInsert);
    tail = toInsert;
}

template <class T>
LinkedList<T>::LinkedList()
:head(NULL),tail(NULL),size(0)
{}


template <class T>
LinkedList<T>::LinkedList(Node<T> *theHead)
:head(theHead),tail(theHead),size(1)
{}
template <class T>
LinkedList<T>::LinkedList(const LinkedList &rhs)
{
    head = rhs.getHead();
    tail = rhs.getTail();
    size = rhs.getSize();
}
template <class T>
LinkedList<T>::~LinkedList()
{}


template <class T>
void LinkedList<T>::setHead(const Node<T> *theHead)
{
    head = theHead;
}

template <class T>
Node<T> *LinkedList<T>::getHead() const
{
    return head;
}
template <class T>
void LinkedList<T>::setTail(const Node<T> *theTail)
{
    tail = theTail;
}

template <class T>
Node<T> *LinkedList<T>::getTail() const
{
    return tail;
}

template <class T>
void LinkedList<T>::setSize(const int theSize)
{
    size = theSize;
}
template <class T>
int LinkedList<T>::getSize() const
{
    return size;
}
template <class T>
LinkedList<T> LinkedList<T>::operator++(int)
{
    size++;
    return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator++()
{
    size++;
    return *this;
}
template <class T>
T *LinkedList<T>::first() const
{
    return getHead()->getKey(); 
}

template <class T>
T *LinkedList<T>::last() const
{
    return getTail()->getKey();
}

template <class T>
Node<T> *LinkedList<T>::getRandomNode()
{
    srand(time(NULL));

    int packIndex = rand()%size;
    Node<T> *cur = head;

    for (int i=0; i<packIndex; i++)
        cur = cur->getNext();
    
    return cur;

}
template <class T>
ostream &operator<<(ostream &out, LinkedList<T> &list)
{
    Node<T> *cur = list.getHead();

    while (cur != NULL)
    {
        out << cur->getKey()->toString() << endl;
        cur = cur->getNext();
    }
    return out;
}

#endif
