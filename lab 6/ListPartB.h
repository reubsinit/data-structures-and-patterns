//
//  ListPartB.h
//  Lab6
//
//  Created by Reuben Wilson on 15/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#ifndef __Lab6__ListPartB__
#define __Lab6__ListPartB__

template<class T>
List<T>::List( const List& aOtherList )
{
    // initialize this list
    fTop = &Node::NIL;					// initialize top
    fLast = &Node::NIL;					// initialize last
    fCount = 0;							// initialize count
    
    // copy aOtherList
    for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
        push_back( *iter );
}

template<class T>
List<T>& List<T>::operator=( const List& aOtherList )
{
    if ( &aOtherList != this )
    {
        // delete this list
        while ( fTop != &Node::NIL )
        {
            Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
            fTop->remove();                         // move first node
            delete fTop;							// free node memory
            fTop = temp;							// make temp the new top
        }
        
        // initialize this list
        fTop = &Node::NIL;					// initialize top
        fLast = &Node::NIL;					// initialize last
        fCount = 0;							// initialize count
        
        // copy aOtherList
        for ( Iterator iter = aOtherList.getIterator(); iter != iter.rightEnd(); iter++ )
            push_back( *iter );
    }
    
    return *this;
}

#endif /* defined(__Lab6__ListPartB__) */
