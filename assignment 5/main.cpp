//
//  main.cpp
//  Assignment 5
//
//  Created by Reuben Wilson on 21/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include "DoublyLinkedNodeIterator.h"

using namespace std;

void testDoublyLinkedNodeIterator()
{
    typedef DoublyLinkedNode<int>::Node IntNode;
    
    IntNode n1( 1 );
    IntNode n2( 2 );
    IntNode n3( 3 );
    IntNode n4( 4 );
    IntNode n5( 5 );
    IntNode n6( 6 );

    n1.append( n6 );
    n1.append( n5 );
    n1.append( n4 );
    n1.append( n3 );
    n1.append( n2 );
    
    DoublyLinkedNodeIterator<int> iter( n6 );
    
    iter--;
    
    cout << "Forward iteration I:" << endl;
    for ( iter++; iter != iter.rightEnd(); iter++ )
        cout << *iter << endl;
    
    cout << "Backward iteration I:" << endl;
    for ( iter--; iter != iter.leftEnd(); iter-- )
        cout << *iter << endl;
    
    cout << "Forward iteration II:" << endl;
    for ( iter = iter.first(); iter != iter.rightEnd(); ++iter )
        cout << *iter << endl;
    
    cout << "Backward iteration II:" << endl;
    for ( iter = iter.last(); iter != iter.leftEnd(); --iter ) 
        cout << *iter << endl; 
}

int main(int argc, const char * argv[])
{
    testDoublyLinkedNodeIterator();
    return 0;
}

