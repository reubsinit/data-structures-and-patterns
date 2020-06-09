//
//  Polynomial.h
//  Assignment 1
//
//  Created by Reuben Wilson on 11/03/2014.
//  Copyright (c) 2014 Reuben Wilson. All rights reserved.
//

#ifndef __Assignment_1__Polynomial__
#define __Assignment_1__Polynomial__

#include <iostream>

#define MAX_DEGREE 20+1+1

class Polynomial
{
private:
    int fDegree;
    double fCoeffs[MAX_DEGREE];
    
public:
    Polynomial();
    Polynomial operator*(const Polynomial& aRight) const;
    friend std::istream& operator>>(std::istream& aIStream, Polynomial& aObject);
    friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject);
    double calculate(double aX) const;
    Polynomial indefiniteIntegral() const;
    double definiteIntegral(double aXLow, double aXHigh) const;
};

#endif /* defined(__Assignment_1__Polynomial__) */
