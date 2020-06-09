//
//  main.cpp
//  Assignment 1
//
//  Created by Reuben Wilson on 11/03/2014.
//  Copyright (c) 2014 Reuben Wilson. All rights reserved.
//

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
    Polynomial A;
    cout << "Specify first polynomial: " << endl;
    cin >> A;
    cout << "A = " << A << endl;
    
    double x;
    cout << "Specify value for x: " << endl;
    cin >> x;
    
    cout << "A(x) = " << A.calculate(x) << endl;
    cout << "Idefinite integral of A = " << A.indefiniteIntegral() << endl;
    cout << "Definitie integral of A(xLow = 0, xHigh = 12) = " << A.definiteIntegral(0, 12) << endl;
    
//    Polynomial B;
//    cout << "Specify second polynomial: " << endl;
//    cin >> B;
//    cout << "B = " << B << endl;
//    
//    Polynomial C = A * B;
//    cout << "C = A * B" << endl;
//    cout << "C = " << C << endl;
    
    return 0;
}

