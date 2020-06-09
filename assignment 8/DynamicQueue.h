//
//  DynamicQueue.h
//  Assignment 8
//
//  Created by Reuben Wilson on 23/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_8__DynamicQueue__
#define __Assignment_8__DynamicQueue__

#include <iostream>

#include "List.h"
#include <stdexcept>

template<class T>
class DynamicQueue
{
private:
	List<T> fElements;
    
public:
	bool isEmpty() const;
	int size() const;
	void enqueue( const T& aElement );
	const T dequeue();
};

template<class T>
bool DynamicQueue<T>::isEmpty() const
{
	return fElements.isEmpty();									// 2
}

template<class T>
int DynamicQueue<T>::size() const
{
	return fElements.size();									// 2
}

template<class T>
void DynamicQueue<T>::enqueue( const T& aElement )
{
	fElements.push_back( aElement );							// 2
}

template<class T>
const T DynamicQueue<T>::dequeue()
{
	if ( !isEmpty() )											// 2
	{
		const T Result = fElements[0];							// 2
		fElements.remove( Result );                             // 2
		return Result;											// 1
	}
	else
		throw std::underflow_error( "Queue is empty!" );		// 1/14
}

#endif /* defined(__Assignment_8__DynamicQueue__) */
