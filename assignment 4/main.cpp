//
//  main.cpp
//  Assignment 4
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "FibonacciIterator.h"

using namespace std;

int main(int argc, const char * argv[])
{
    if (argc < 2)
    {
        cerr << "There is an argument missing!" << endl;
        cerr << "Usage: FibonacciIterator" << endl;
        return 1;
    }

    cout << "Fibonacci sequence up to " << argv[1] << endl;
    
    FibonacciIterator lIterator(atoi(argv[1]));
    
    for (; lIterator != lIterator.end(); lIterator++)
    {
        cout << *lIterator << endl;
    }
    
    cout << "Once more: " << endl;
    FibonacciIterator lIterator2 = lIterator.begin();
    
    for (; lIterator2 != lIterator2.end(); lIterator2++)
    {
        cout << *lIterator2 << endl;
    }
    return 0;
}
