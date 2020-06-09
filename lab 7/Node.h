//
//  Node.h
//  Lab7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab7__Node__
#define __Lab7__Node__

#include <iostream>
template<class DataType>
class Node
{
public:
	const DataType& fValue;
	Node<DataType>* fNext;
	Node<DataType>* fPrevious;
    
	Node( const DataType& aValue,
         Node<DataType>* aNext = (Node<DataType>*)0,
         Node<DataType>* aPrevious = (Node<DataType>*)0 ) : fValue( aValue )
	{
		fNext = aNext;
		if ( fNext != (Node<DataType>*)0 )
			fNext->fPrevious = this;
        
		fPrevious = aPrevious;
		if ( fPrevious != (Node<DataType>*)0 )
			fPrevious->fNext = this;
	}
    
	~Node()
	{
		if ( fNext != (Node<DataType>*)0 )
			fNext->fPrevious = fPrevious;
        
		if ( fPrevious != (Node<DataType>*)0 )
			fPrevious->fNext = fNext;
	}
};

#endif /* defined(__Lab7__Node__) */
