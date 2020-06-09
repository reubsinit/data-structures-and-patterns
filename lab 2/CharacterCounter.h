//
//  CharacterCounter.h
//  Lab2
//
//  Created by Reuben Wilson on 21/03/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab2__CharacterCounter__
#define __Lab2__CharacterCounter__

#include <iostream>

class CharacterCounter
{
private:
    int fTotalNumberOfCharacters;
    int fCharacterCounts[256];
    
public:
    CharacterCounter();
    void count(unsigned char aCharacter);
    friend std::ostream& operator<<(std::ostream& aOStream, const CharacterCounter& aCharacterCounter);
};

#endif /* defined(__Lab2__CharacterCounter__) */
