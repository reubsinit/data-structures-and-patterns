//
//  List.h
//  Assignment 6
//
//  Created by Reuben Wilson on 30/04/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_6__List__
#define __Assignment_6__List__

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template<class T>
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;
    
	Node* fTop;		// the first element in the list
	Node* fLast;	// the last element in the list
	int fCount;		// number of elements in the list
    
public:
	// auxiliary definition to simplify iterator usage
	typedef DoublyLinkedNodeIterator<T> Iterator;
    
	List();							// default constructor - creates empty list
	~List();						// destructor - frees all nodes
    
	bool isEmpty() const;	// Is list empty?
	int size() const;		// list size
    
	void push_front( const T& aElement );	// adds a node initialized with aElement at front
	void push_back( const T& aElement );	// adds a node initialized with aElement at back
	
	void remove( const T& aElement );	// remove node that matches aElement from list
    
    List<T>& operator=( const List& aOtherList );
    List( const List& aOtherList );
    
	const T& operator[]( unsigned int aIndex ) const;	// list indexer
	
	Iterator getIterator() const;	// return an iterator for the nodes of the list
};

template<class T>
List<T>::~List()
{
	while ( fTop != &Node::NIL )
	{
		Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
		fTop->remove();                         // move first node
		delete fTop;							// free node memory
		fTop = temp;							// make temp the new top
	}
}

template<class T>
bool List<T>::isEmpty() const
{
	return fTop == &Node::NIL;
}

template<class T>
int List<T>::size() const
{
	return fCount;
}

template<class T>
void List<T>::push_front( const T &aElement )
{
	Node* lNewElement = new Node( aElement );	// create a new node
    
	if ( fTop == &Node::NIL )					// Is this the first node?
	{
		fTop = lNewElement;						// make lNewNode first node
		fLast = lNewElement;					// make lNewNode last node as well
	}
	else
	{
		fTop->prepend( *lNewElement );          // make lNewElement previous of top
		fTop = lNewElement;						// make lNewNode first node
	}
    
	fCount++;									// increment count
}

template<class T>
List<T>::List()
{
    fTop = &Node::NIL;
    fLast = &Node::NIL;
    fCount = 0;
}

template<class T>
DoublyLinkedNodeIterator<T> List<T>::getIterator() const
{
    DoublyLinkedNodeIterator<T> lIter(*fLast);
    return lIter;
}

template<class T>
void List<T>::push_back(const T &aElement)
{
    Node* lNewElement = new Node(aElement);
    
    if (fLast == &Node::NIL)
    {
        fLast = lNewElement;
        fTop = lNewElement;
    }
    else
    {
        fLast->append(*lNewElement);
        fLast = lNewElement;
    }
    fCount++;
}

template<class T>
void List<T>::remove(const T& aElement)
{
    Node* lNode = fTop;
    
    while (lNode != &Node::NIL)
    {
        if (lNode->getValue() == aElement)
            break;
        lNode = (Node *)&lNode->getNext();
    }
    
    
    if (lNode != &Node::NIL)
    {
        if (lNode == fTop)
        {
            fTop = (Node *)&lNode->getNext();
        }
        if (lNode == fLast)
        {
            fLast = (Node *)&lNode->getPrevious();
        }
        
        lNode->remove();
        delete lNode;
        fCount--;
    }
}

template<class T>
const T& List<T>::operator[](unsigned int aIndex) const
{
    Node* lTempNode = &Node::NIL;
    if (aIndex >= fCount)
    {
        throw std::out_of_range ("The index you've specified is out of range!");
    }
    else if (aIndex == 0)
    {
        return fTop->getValue();
    }
    else
    {
        lTempNode = (Node *)&fTop->getNext();
        while (aIndex > 1)
        {
            lTempNode = (Node *)&lTempNode->getNext();
            aIndex--;
        }
        return lTempNode->getValue();
    }
}

template<class T>
List<T>::List( const List& aOtherList )
{
    // initialize this list
    fTop = &Node::NIL;					// initialize top
    fLast = &Node::NIL;					// initialize last
    fCount = 0;							// initialize count
    
    // copy aOtherList
    for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
        push_back( *iter );
}

template<class T>
List<T>& List<T>::operator=( const List& aOtherList )
{
    if ( &aOtherList != this )
    {
        // delete this list
        while ( fTop != &Node::NIL )
        {
            Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
            fTop->remove();                         // move first node
            delete fTop;							// free node memory
            fTop = temp;							// make temp the new top
        }
        
        // initialize this list
        fTop = &Node::NIL;					// initialize top
        fLast = &Node::NIL;					// initialize last
        fCount = 0;							// initialize count
        
        // copy aOtherList
        for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
            push_back( *iter );
    }
    
    return *this;
}

#endif /* defined(__Assignment_6__List__) */
