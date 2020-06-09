//
//  HexDump.h
//  Assignment 3
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_3__HexDump__
#define __Assignment_3__HexDump__

#include <iostream>
#include <fstream>
#include <string>

#define BYTE_SIZE 16

class HexDump
{
private:
    std::ifstream fInput;
    
public:
    bool open(const std::string& aInputFileName);
    void close();
    void processInput();
};

#endif /* defined(__Assignment_3__HexDump__) */
