//
//  List.h
//  Lab7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab7__List__
#define __Lab7__List__

#include "NodeIterator.h"

template<class ElementType>
class List
{
private:
	typedef Node<ElementType>* ListImpl;
	typedef Node<ElementType> Value;
    
	ListImpl fTop;
	ListImpl fLast;
    
public:
    
	typedef NodeIterator<ElementType> ListIterator;
    
	List()
	{
		fTop = (ListImpl)0;
		fLast = (ListImpl)0;
	}
    
	List( const List<ElementType>& aOtherList )
	{
		fTop = (ListImpl)0;
		fLast = (ListImpl)0;

		for ( ListIterator iter = aOtherList.iterator(); iter != iter.end(); iter++ )
        {
            add(*iter);
        }
	}
    
	~List()
	{
		while ( fTop )
			deleteLast();
	}
    
	void add( const ElementType& aElement )
	{
		ListImpl lNewNode =
        new Value( aElement, (ListImpl)0, fLast );
        
		if	 ( fTop == (ListImpl)0 )
			fTop = lNewNode;
        
		fLast = lNewNode;
	}
    
	void deleteLast()
	{
		if ( fLast != (ListImpl)0 )
		{
			ListImpl lElem = fLast;
			fLast = fLast->fPrevious;
            
			if ( fLast == (ListImpl)0 )
				fTop = (ListImpl)0;
            
			delete lElem;
		}
	}
    
	ListIterator iterator() const
	{
		return ListIterator( fTop );
	}
};

#endif /* defined(__Lab7__List__) */
