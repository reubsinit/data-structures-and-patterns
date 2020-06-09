//
//  DoublyLinkedNodeIterator.h
//  Assignment 5
//
//  Created by Reuben Wilson on 21/04/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_5__DoublyLinkedNodeIterator__
#define __Assignment_5__DoublyLinkedNodeIterator__

#include "DoublyLinkedNode.h"

template<class DataType>
class DoublyLinkedNodeIterator
{
private:
    typedef DoublyLinkedNode<DataType> Node;
    enum IteratorStates {BEFORE, DATA, AFTER};
    IteratorStates fState;
    const Node* fLeftMost;
    const Node* fRightMost;
    const Node* fCurrent;
    
public:
    typedef DoublyLinkedNodeIterator<DataType> Iterator;
    DoublyLinkedNodeIterator(const Node& aList);
    const DataType& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    
    bool operator==(const Iterator& aOtherIter) const;
    bool operator!=(const Iterator& aOtherIter) const;
    
    Iterator leftEnd() const;
    Iterator first() const;
    Iterator last() const;
    Iterator rightEnd() const;
};

template<class DataType>
DoublyLinkedNodeIterator<DataType>::DoublyLinkedNodeIterator(const Node& aList)
{
    fLeftMost = &aList;
    while (&fLeftMost->getPrevious() != &Node::NIL)
    {
        fLeftMost = &fLeftMost->getPrevious();
    }
    fCurrent = fLeftMost;
    
    if (fCurrent != &Node::NIL)
        fState = DATA;
    else
        fState = AFTER;
    fRightMost = &aList;
    
    while (&fRightMost->getNext() != &Node::NIL)
    {
        fRightMost = &fRightMost->getNext();
    }
}

template<class DataType>
const DataType& DoublyLinkedNodeIterator<DataType>::operator*() const
{
    return fCurrent->getValue();
}

template<class DataType>
DoublyLinkedNodeIterator<DataType>& DoublyLinkedNodeIterator<DataType>::operator++()
{
    DoublyLinkedNodeIterator<DataType> &temp = *this;
    switch (temp.fState)
    {
        case BEFORE:
            temp = first();
            if (temp == last())
            {
                temp = rightEnd();
            }
            break;
            
        case DATA:
            if (temp != last())
            {
                temp.fCurrent = &temp.fCurrent->getNext();
            }
            else
            {
                temp = rightEnd();
            }
            break;
            
        case AFTER:
            temp = rightEnd();
            break;
    }
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::operator++(int)
{
    DoublyLinkedNodeIterator<DataType> temp = *this;
    ++(*this);
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType>& DoublyLinkedNodeIterator<DataType>::operator--()
{
    DoublyLinkedNodeIterator<DataType> &temp = *this;
    switch (temp.fState)
    {
        case BEFORE:
            temp = leftEnd();
            break;
            
        case DATA:
            if (temp != first())
            {
                temp.fCurrent = &temp.fCurrent->getPrevious();
            }
            else
            {
                temp = leftEnd();
            }
            break;
            
        case AFTER:
            temp = last();
            if (temp == first())
            {
                temp = leftEnd();
            }
            break;
    }
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::operator--(int)
{
    DoublyLinkedNodeIterator<DataType> temp = *this;
    --(*this);
    return temp;
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator==(const DoublyLinkedNodeIterator<DataType>& aOtherIter) const
{
    return ((this->fState == aOtherIter.fState) &&
            (this->fRightMost->getValue() == aOtherIter.fRightMost->getValue()) &&
            (this->fLeftMost->getValue() == aOtherIter.fLeftMost->getValue()) &&
            (this->fCurrent->getValue() == aOtherIter.fCurrent->getValue()));
}

template<class DataType>
bool DoublyLinkedNodeIterator<DataType>::operator!=(const Iterator &aOtherIter) const
{
    return !(*this == aOtherIter);
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::leftEnd() const
{
    DoublyLinkedNodeIterator<DataType> temp = first();
    temp.fState = BEFORE;
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::first() const
{
    DoublyLinkedNodeIterator<DataType> temp = *this;
    temp.fCurrent = temp.fLeftMost;
    temp.fState = DATA;
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::last() const
{
    DoublyLinkedNodeIterator<DataType> temp = *this;
    temp.fCurrent = temp.fRightMost;
    temp.fState = DATA;
    return temp;
}

template<class DataType>
DoublyLinkedNodeIterator<DataType> DoublyLinkedNodeIterator<DataType>::rightEnd() const
{
    DoublyLinkedNodeIterator<DataType> temp = last();
    temp.fState = AFTER;
    return temp;
}

#endif /* defined(__Assignment_5__DoublyLinkedNodeIterator__) */
