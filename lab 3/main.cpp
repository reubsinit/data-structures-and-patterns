//
//  main.cpp
//  Lab3
//
//  Created by Reuben Wilson on 28/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Caesar.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Missing arguments, brah" << endl;
        return 1;
    }
    
    Caesar lCaesar;
    
    ifstream lInput;
    ofstream lOutput;
    
    cout << argv[1] << ", " << argv[2];
    
    lInput.open(argv[1], ifstream::in);
    lOutput.open(argv[2], ofstream::out);

    
    lCaesar.shiftByFour(lInput, lOutput);
    
    lInput.close();
    lOutput.close();
    
    return 0;
}

