//
//  CharacterCounter.cpp
//  Lab2
//
//  Created by Reuben Wilson on 21/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <cctype>

#include "CharacterCounter.h"

using namespace std;

CharacterCounter::CharacterCounter()
{
    fTotalNumberOfCharacters = 0;
    for (int i = 0; i < 256; i++)
    {
        fCharacterCounts[i] = 0;
    }
}

void CharacterCounter::count(unsigned char aCharacter)
{
    fTotalNumberOfCharacters++;
    fCharacterCounts[aCharacter]++;
}

ostream& operator << (std::ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
    cout << "Character count for " << aCharacterCounter.fTotalNumberOfCharacters << " characters." << endl;
    for (int i = 0; i < 256; i++)
    {
        if (aCharacterCounter.fCharacterCounts[i])
        {
            aOStream << (unsigned char) i << ":\t" << aCharacterCounter.fCharacterCounts[i] << endl;
        }
    }
    return aOStream;
}