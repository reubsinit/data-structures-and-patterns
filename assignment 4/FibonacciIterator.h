//
//  FibonacciIterator.h
//  Assignment 4
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_4__FibonacciIterator__
#define __Assignment_4__FibonacciIterator__

#include <iostream>

class FibonacciIterator
{
private:
    long fMaxN;
    long fCurrentN;
    long fPrevious;
    long fCurrent;
    
public:
    FibonacciIterator(long aMaxN);
    const long& operator*() const;
    FibonacciIterator operator++();
    FibonacciIterator operator++(int);
    bool operator==(const FibonacciIterator& aOther) const;
    bool operator!=(const FibonacciIterator& aOther) const;
    
    FibonacciIterator begin() const;
    FibonacciIterator end() const;
};

#endif /* defined(__Assignment_4__FibonacciIterator__) */
