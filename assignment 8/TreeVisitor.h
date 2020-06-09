//
//  TreeVisitor.h
//  Assignment 8
//
//  Created by Reuben Wilson on 23/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_8__TreeVisitor__
#define __Assignment_8__TreeVisitor__

#include <iostream>

template<class T>
class TreeVisitor
{
public:
	virtual ~TreeVisitor() {}	// virtual default destructor
	
	// default behavior
	virtual void preVisit( const T& aKey ) const
	{
//        visit(aKey);
    }
    
	virtual void postVisit( const T& aKey ) const
	{
//        visit(aKey);
    }
    
	virtual void inVisit( const T& aKey ) const
	{
//        visit(aKey);
    }
    
	virtual void visit( const T& aKey ) const
	{
		std::cout << aKey << " ";
	}
};

template<class T>
class PreOrderVisitor : public TreeVisitor<T>
{
public:
    
	// override pre-order behavior
	virtual void preVisit( const T& aKey ) const
	{
		this->visit( aKey ); 	// invoke default behavior
	}
};

template<class T>
class PostOrderVisitor : public TreeVisitor<T>
{
public:
    
	// override post-order behavior
	virtual void postVisit( const T& aKey ) const
	{
		this->visit( aKey ); 	// invoke default behavior
	}
};

#endif /* defined(__Assignment_8__TreeVisitor__) */
