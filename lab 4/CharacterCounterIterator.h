//
//  CharacterCounterIterator.h
//  Lab4
//
//  Created by Reuben Wilson on 4/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab4__CharacterCounterIterator__
#define __Lab4__CharacterCounterIterator__

#include "CharacterCounter.h"
#include "FrequencyMap.h"

class CharacterCounterIterator
{
private:
    FrequencyMap fMaps[256];
    int fIndex;
    
public:
    CharacterCounterIterator(CharacterCounter& aCounter);
    
    const FrequencyMap& operator * () const;
    CharacterCounterIterator& operator ++ ();
    CharacterCounterIterator operator ++ (int);
    bool operator == (const CharacterCounterIterator& aOther) const;
    bool operator != (const CharacterCounterIterator& aOther) const;
    
    CharacterCounterIterator begin() const;
    CharacterCounterIterator end() const;
};

#endif /* defined(__Lab4__CharacterCounterIterator__) */
