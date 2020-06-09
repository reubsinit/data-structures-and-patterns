//
//  FibonacciIterator.cpp
//  Assignment 4
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include "FibonacciIterator.h"

FibonacciIterator::FibonacciIterator(long aMaxN)
{
    fMaxN = aMaxN;
    fCurrentN = 0;
    fPrevious = 0;
    fCurrent = 1;
}

const long& FibonacciIterator::operator*() const
{
    return fCurrent;
}

FibonacciIterator FibonacciIterator::operator++()
{
    long lNext = 0;
    lNext = fCurrent + fPrevious;
    fPrevious = fCurrent;
    fCurrent = lNext;
    fCurrentN += 1;
    return *this;
}

FibonacciIterator FibonacciIterator::operator++(int)
{
    FibonacciIterator temp = *this;
    ++(*this);
    return temp;
}

bool FibonacciIterator::operator==(const FibonacciIterator &aOther) const
{
    return ((fMaxN == aOther.fMaxN) &&
            (fCurrentN == aOther.fCurrentN));
}

bool FibonacciIterator::operator!=(const FibonacciIterator &aOther) const
{
    return !(*this == aOther);
}

FibonacciIterator FibonacciIterator::begin() const
{
    FibonacciIterator temp(this->fMaxN);
    return temp;
}

FibonacciIterator FibonacciIterator::end() const
{
    FibonacciIterator temp(this->fMaxN);
    temp.fCurrentN = this->fMaxN;
    return temp;
}