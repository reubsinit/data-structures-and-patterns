//
//  CharacterCounter.h
//  Lab4
//
//  Created by Reuben Wilson on 4/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab4__CharacterCounter__
#define __Lab4__CharacterCounter__

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
    int operator [] (unsigned char aCharacter) const;
};

#endif /* defined(__Lab4__CharacterCounter__) */
