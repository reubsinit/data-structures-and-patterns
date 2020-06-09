//
//  NodeIterator.h
//  Lab7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab7__NodeIterator__
#define __Lab7__NodeIterator__

#include "Node.h"

template<class DataType>
class NodeIterator
{
private:
	enum IteratorStates { DATA , END };
    
	typedef Node<DataType>* NodeImpl;
    
	NodeImpl fTop;
	NodeImpl fLast;
	NodeImpl fCurrent;
	IteratorStates fState;
    
public:
	NodeIterator( NodeImpl aList )
	{
		fTop = aList;
        
		// set current to top element;
		fCurrent = fTop;
        
		// set fLAST
		if ( aList )
		{
			fLast = aList;
			while ( fLast->fNext != (NodeImpl)0 )
				fLast = fLast->fNext;
		}
		else
			fLast = (NodeImpl)0;
        
		// set state
		fState = fCurrent ? DATA : END;
	}
    
	const DataType& operator*() const
	{
		return fCurrent->fValue;
	}
    
	NodeIterator& operator++()	// prefix increment
	{
		if ( fState == DATA )
		{
			fCurrent = fCurrent->fNext;
            
			// end of list?
			if ( fCurrent == (Node<DataType>*)0 )
				fState = END;
		}
        
		return *this;
	}
    
	NodeIterator operator++(int)	// postfix increment
	{
		NodeIterator<DataType> Result = *this;
		++(*this);
		return Result;
	}
    
	bool operator==( const NodeIterator& aOtherIter ) const
	{
		return (fCurrent == aOtherIter.fCurrent) &&
        (fTop == aOtherIter.fTop) &&
        (fState == aOtherIter.fState);
	}
    
	bool operator!=( const NodeIterator& aOtherIter ) const
	{
		return !(*this == aOtherIter);
	}
    
	NodeIterator end() const
	{
		NodeIterator<DataType> Result = *this;
		Result.fCurrent = (NodeImpl)0;
		Result.fState = END;
        
		return Result;
	}
    
};

#endif /* defined(__Lab7__NodeIterator__) */
