//
//  main.cpp
//  Assignment 3
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include "HexDump.h"
#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    if (argc < 2)
    {
        cerr << "Error: Argument missing!" << endl;
        cerr << "Usage: HexDump filename" << endl;
        return 1;
    }
    
    HexDump lProcessor;
    
    if (lProcessor.open(argv[1]))
    {
        lProcessor.processInput();
        lProcessor.close();
        return 0;
    }
    
    return 2;
}

