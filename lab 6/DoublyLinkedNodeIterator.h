//
//  DoublyLinkedNodeIterator.h
//  Lab6
//
//  Created by Reuben Wilson on 9/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab6__DoublyLinkedNodeIterator__
#define __Lab6__DoublyLinkedNodeIterator__

#include <iostream>

#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedNodeIterator
{
private:
	enum IteratorStates { BEFORE, DATA , AFTER };
	
	IteratorStates fState;
    
	typedef DoublyLinkedNode<DataType> Node;
    
	const Node* fLeftmost;
	const Node* fRightmost;
	const Node* fCurrent;
    
public:
	typedef DoublyLinkedNodeIterator<DataType> Iterator;
    
	DoublyLinkedNodeIterator( const Node& aList );
	
	const DataType& operator*() const;	// dereference
	Iterator& operator++();				// prefix increment
	Iterator operator++(int);			// postfix increment
	Iterator& operator--();				// prefix decrement
	Iterator operator--(int);			// postfix decrement
    
	bool operator==( const Iterator& aOtherIter ) const;
	bool operator!=( const Iterator& aOtherIter ) const;
    
	Iterator leftEnd() const;
	Iterator first() const;
	Iterator last() const;
	Iterator rightEnd() const;
};

// implementation

template<class DataType>
DoublyLinkedNodeIterator<DataType>::DoublyLinkedNodeIterator( const Node& aList )
{
	// set leftmost element
	fLeftmost = &aList;															// 2
    
	while ( &fLeftmost->getPrevious() != &Node::NIL )							// 3
	{
		fLeftmost = &fLeftmost->getPrevious();									// 2
	}
    
	// set current to first
	fCurrent = fLeftmost;														// 1
    
	if ( fCurrent != &Node::NIL )												// 2
		fState = DATA;
	else
		fState = BEFORE;														// 1
    
	// set rightmost element
	fRightmost = &aList;														// 2
    
	while ( &fRightmost->getNext() != &Node::NIL )								// 3
	{
		fRightmost = &fRightmost->getNext();									// 2/18
	}
}

template<class DataType>
const DataType& DoublyLinkedNodeIterator<DataType>::operator*() const
{
	return fCurrent->getValue();												// 2
}

template<class DataType>
DoublyLinkedNodeIterator<DataType>& DoublyLinkedNodeIterator<DataType>::operator++()
{
    // or if-then-else
	switch ( fState )															// 2
	{
        case BEFORE:																// 1
            fCurrent = fLeftmost;													// 1
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = AFTER;
            }
            else
            {
                fState = DATA;														// 2
            }
            break;
        case DATA:																	// 1
            fCurrent = &fCurrent->getNext();										// 2
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = AFTER;														// 1
            }
            break;
        default: ;
	}
    
	return *this;																// 1/15
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::operator++(int)
{
	Iterator temp = *this;														// 2
    
	++(*this);																	// 2
    
	return temp;																// 1/5
}

template<class DataType>
DoublyLinkedNodeIterator<DataType>& DoublyLinkedNodeIterator<DataType>::operator--()
{
	switch ( fState )															// 2
	{
        case AFTER:																	// 1
            fCurrent = fRightmost;													// 1
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = BEFORE;
            }
            else
            {
                fState = DATA;														// 2
            }
            break;
        case DATA:																	// 1
            fCurrent = &fCurrent->getPrevious();									// 2
            if ( fCurrent == &Node::NIL )											// 2
            {
                fState = BEFORE;													// 1
            }
            break;
        default: ;
	}
    
	return *this;																// 1/15
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::operator--(int)
{
	Iterator temp = *this;														// 2
    
	--(*this);																	// 2
    
	return temp;																// 1/5
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator==( const Iterator& aOtherIter ) const
{
	return fLeftmost == aOtherIter.fLeftmost &&									// 2
    fRightmost == aOtherIter.fRightmost &&									// 2
    fCurrent == aOtherIter.fCurrent &&										// 2
    fState == aOtherIter.fState;											// 2/8
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator!=( const Iterator& aOtherIter ) const
{
	return !(*this == aOtherIter);												// 2
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::leftEnd() const
{
	Iterator temp = *this;														// 2
    
	temp.fCurrent = &Node::NIL;													// 2
	temp.fState = BEFORE;														// 1
    
	return temp;																// 1/6
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::first() const
{
	return ++(leftEnd());														// 2
}

template<class DataType> 
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::last() const
{
	return --(rightEnd());														// 2
}

template<class DataType> 
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::rightEnd() const
{
	Iterator temp = *this;														// 2
    
	temp.fCurrent = &Node::NIL;													// 2
	temp.fState = AFTER;														// 1
    
	return temp;																// 1/6
}

#endif /* defined(__Lab6__DoublyLinkedNodeIterator__) */
