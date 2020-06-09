//
//  FrequencyMap.cpp
//  Lab4
//
//  Created by Reuben Wilson on 4/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include "FrequencyMap.h"

FrequencyMap::FrequencyMap()
{
    fChar = '0';
    fFrequency = 0;
}

FrequencyMap::FrequencyMap( char aChar, int aFrequency )
{
	fChar = aChar;
	fFrequency = aFrequency;
}

char FrequencyMap::getCharacter() const
{
	return fChar;
}

int FrequencyMap::getFrequency() const
{
	return fFrequency;
}