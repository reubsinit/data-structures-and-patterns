//
//  DynamicStackIterator.h
//  Assignment 7
//
//  Created by Reuben Wilson on 15/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_7__DynamicStackIterator__
#define __Assignment_7__DynamicStackIterator__

#include "DynamicStack.h"

template<class T>
class DynamicStackIterator
{
private:
    DynamicStack<T> fStack;
    
public:
    DynamicStackIterator(const DynamicStack<T>& aStack);
    
    const T& operator*() const; // dereference
    DynamicStackIterator& operator++(); // prefix increment
    DynamicStackIterator operator++(int); // postfix increment
    bool operator==(const DynamicStackIterator& aOtherIter) const;
    bool operator!=(const DynamicStackIterator& aOtherIter) const;
    
    DynamicStackIterator end() const; // new iterator (after last element)
};

template<class T>
DynamicStackIterator<T>::DynamicStackIterator(const DynamicStack<T>& aStack)
{
    fStack = aStack;
}

template<class T>
const T& DynamicStackIterator<T>::operator*() const
{
    return fStack.top();
}

template<class T>
DynamicStackIterator<T>& DynamicStackIterator<T>::operator++()
{
    fStack.pop();
    return *this;
}

template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::operator++(int)
{
    DynamicStackIterator<T> temp = *this;
    ++(*this);
    return temp;
}

template<class T>
bool DynamicStackIterator<T>::operator==(const DynamicStackIterator<T> &aOtherIter)const
{
    return fStack.size() == aOtherIter.fStack.size();
}

template<class T>
bool DynamicStackIterator<T>::operator!=(const DynamicStackIterator<T> &aOtherIter)const
{
    return !(*this == aOtherIter);
}

template<class T>
DynamicStackIterator<T> DynamicStackIterator<T>::end()const
{
    return DynamicStackIterator<T>(DynamicStack<T>());
}

#endif /* defined(__Assignment_7__DynamicStackIterator__) */
