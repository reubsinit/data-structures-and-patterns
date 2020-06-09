//
//  DynamicQueueIterator.h
//  Assignment 7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_7__DynamicQueueIterator__
#define __Assignment_7__DynamicQueueIterator__

#include "DynamicQueue.h"

template<class T>
class DynamicQueueIterator
{
private:
    DynamicQueue<T> fQueue;
    T fCurrentElement;
    bool fMustDequeue;
    
public:
    DynamicQueueIterator( const DynamicQueue<T>& aQueue );
    
    const T& operator*(); // dereference
    DynamicQueueIterator& operator++(); // prefix increment
    DynamicQueueIterator operator++(int); // postfix increment
    bool operator==( const DynamicQueueIterator& aOtherIter ) const;
    bool operator!=( const DynamicQueueIterator& aOtherIter ) const;
    DynamicQueueIterator end() const; // new iterator (after last element)
};

template<class T>
DynamicQueueIterator<T>::DynamicQueueIterator(const DynamicQueue<T>& aQueue)
{
    fQueue = aQueue;
    if (!fQueue.isEmpty())
    {
        fCurrentElement = fQueue.dequeue();
    }
    fMustDequeue = false;
}

template<class T>
const T& DynamicQueueIterator<T>::operator*()
{
    if (fMustDequeue)
    {
        fCurrentElement = fQueue.dequeue();
        fMustDequeue = false;
    }
    return fCurrentElement;
}

template<class T>
DynamicQueueIterator<T>& DynamicQueueIterator<T>::operator++()
{
    if (fMustDequeue)
    {
        fQueue.dequeue();
    }
    fMustDequeue = true;
    return *this;
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::operator++(int)
{
    DynamicQueueIterator<T> temp = *this;
    ++(*this);
    return temp;
}

template<class T>
bool DynamicQueueIterator<T>::operator==(const DynamicQueueIterator& aOtherIter)const
{
    return (fQueue.size() == aOtherIter.fQueue.size());
}

template<class T>
bool DynamicQueueIterator<T>::operator!=(const DynamicQueueIterator& aOtherIter)const
{
    return !(*this == aOtherIter);
}

template<class T>
DynamicQueueIterator<T> DynamicQueueIterator<T>::end() const
{
    return DynamicQueueIterator<T>(DynamicQueue<T>());
}

#endif /* defined(__Assignment_7__DynamicQueueIterator__) */
