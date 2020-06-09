//
//  main.cpp
//  Lab2
//
//  Created by Reuben Wilson on 21/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "CharacterCounter.h"

using namespace std;

int main(int argc, char* argv[])
{
    CharacterCounter lCounter;
    
    unsigned char lChar;
    
    ifstream lInput;
    
    lInput.open(argv[1]);
    
    while (lInput >> lChar)
    {
        lCounter.count(lChar);
    }
    
    cout << lCounter;
    
    return 0;
}

