//
//  DynamicQueue.h
//  Assignment 7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_7__DynamicQueue__
#define __Assignment_7__DynamicQueue__

#include "List.h"
#include <stdexcept>

template<class T>
class DynamicQueue
{
private:
    List<T> fElements;
    
public:
    bool isEmpty() const;
    int size() const;
    void enqueue( const T& aElement );
    const T dequeue();
};

template<class T>
bool DynamicQueue<T>::isEmpty() const
{
    return fElements.isEmpty();
}

template<class T>
int DynamicQueue<T>::size() const
{
    return fElements.size();
}

template<class T>
void DynamicQueue<T>::enqueue(const T& aElement)
{
    return fElements.push_back(aElement);
}

template<class T>
const T DynamicQueue<T>::dequeue()
{
    if (!this->isEmpty())
    {
        const T lResult = fElements[0];
        fElements.remove(fElements[0]);
        return lResult;
    }
    else
    {
        throw std::underflow_error( "There are no elements in the list.");
    }
}
#endif /* defined(__Assignment_7__DynamicQueue__) */
