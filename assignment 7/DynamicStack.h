//
//  DynamicStack.h
//  Assignment 7
//
//  Created by Reuben Wilson on 15/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_7__DynamicStack__
#define __Assignment_7__DynamicStack__

#include <iostream>
#include "List.h"
#include <stdexcept>

template<class T>
class DynamicStack
{
private:
    List<T> fElements;
    
public:
    bool isEmpty() const;
    int size() const;
    void push(const T& aItem);
    void pop();
    const T& top() const;
};

template<class T>
bool DynamicStack<T>::isEmpty() const
{
    return fElements.isEmpty();
}

template<class T>
int DynamicStack<T>::size() const
{
    return fElements.size();
}

template<class T>
void DynamicStack<T>::push(const T& aItem)
{
    fElements.push_front(aItem);
}

template<class T>
void DynamicStack<T>::pop()
{
    if (!this->isEmpty())
    {
        fElements.remove(fElements[0]);
    }
    else
    {
        throw std::range_error( "There are no elements in the list.");
    }
}

template<class T>
const T& DynamicStack<T>::top() const
{
    if (!this->isEmpty())
    {
        return fElements[0];
    }
    else
    {
        throw std::range_error( "There are no elements in the list.");
    }
}


#endif /* defined(__Assignment_7__DynamicStack__) */
