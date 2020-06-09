//
//  FrequencyMap.h
//  Lab4
//
//  Created by Reuben Wilson on 4/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab4__FrequencyMap__
#define __Lab4__FrequencyMap__

#include <iostream>

class FrequencyMap
{
private:
    char fChar;
    int fFrequency;
    
public:
    FrequencyMap();
    FrequencyMap(char aChar, int aFrequency);
    
    char getCharacter() const;
    int getFrequency() const;
};

#endif /* defined(__Lab4__FrequencyMap__) */
