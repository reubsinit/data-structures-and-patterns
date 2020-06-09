//
//  Caesar.cpp
//  Lab3
//
//  Created by Reuben Wilson on 28/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <cctype>
#include "Caesar.h"

using namespace std;

Caesar::Caesar()
{
    for (int i = 0; i < 26; i++)
    {
        fCharacterFrequenciesBefore[i] = 0;
        fCharacterFrequenciesAfter[i] = 0;
    }
}

void Caesar::shiftByFour(std::ifstream &aInput, std::ofstream &aOutput)
{
    char lOldChar = (char) aInput.get();
    char lNewChar;
    
    while (aInput.good())
    {
        if (isalpha(lOldChar))
        {
            bool lLower = islower(lOldChar);
            lOldChar = (char) toupper(lOldChar);
            fCharacterFrequenciesBefore[lOldChar - 'A']++;
            lNewChar = (char) 'A' + ((lOldChar - 'A' + 4) % 26);
            fCharacterFrequenciesAfter[lNewChar - 'A']++;
            if (lLower)
            {
                lNewChar = (char) tolower(lNewChar);
            }
            aOutput << lNewChar;
        }
        else
        {
            aOutput << lOldChar;
        }
        lOldChar = (char) aInput.get();
    }
}

ostream& operator<<(std::ostream& aOStream, const Caesar& aObject)
{
    for (int i = 0; i < sizeof(aObject.fCharacterFrequenciesAfter); i++)
    {
        if (aObject.fCharacterFrequenciesAfter[i])
        {
            aOStream << (unsigned char) aObject.fCharacterFrequenciesAfter[i];
        }
    }
    return aOStream;
}