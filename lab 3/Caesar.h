//
//  Caesar.h
//  Lab3
//
//  Created by Reuben Wilson on 28/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab3__Caesar__
#define __Lab3__Caesar__

#include <iostream>
#include <fstream>

class Caesar
{
private:
    int fCharacterFrequenciesBefore[26];
    int fCharacterFrequenciesAfter[26];
    
public:
    Caesar();
    void shiftByFour(std::ifstream& aInput, std::ofstream& aOutput);
    friend std::ostream& operator<<(std::ostream& aOStream, const Caesar& aObject);
};

#endif /* defined(__Lab3__Caesar__) */
