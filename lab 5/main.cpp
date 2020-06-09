//
//  main.cpp
//  Lab5
//
//  Created by Reuben Wilson on 11/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include "DoublyLinkedNode.h"

#include <iostream>
#include <string>

using namespace std;

void test1()
{
    string s1( "One" );
    string s2( "Two" );
    string s3( "Three" );
    string s4( "Four" );
    
    typedef DoublyLinkedNode<string>::Node StringNode;
    
    StringNode n1( s1 );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( s4 );
    
    cout << "Test append:" << endl;
    
    n1.append( n4 );
    n1.append( n3 );
    n1.append( n2 );
    
    cout << "Three elements:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else
            cout << "<NULL>";
        
        cout << "," << pn->getValue()<< ",";
        
        if ( &pn->getNext() != &StringNode::NIL )
            cout << pn->getNext().getValue();
        else
            cout << "<NULL>";
        
        cout << ")" << endl;
    }
    
    n2.remove();
    
    cout << "Two elements:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else 
            cout << "<NULL>"; 
        
        cout << "," << pn->getValue() << ","; 
        
        if ( &pn->getNext() != &StringNode::NIL ) 
            cout << pn->getNext().getValue(); 
        else 
            cout << "<NULL>"; 
        
        cout << ")" << endl; 
    } 
}

void test2()
{
    string s1( "One" );
    string s2( "Two" );
    string s3( "Three" );
    string s4( "Four" );
    
    typedef DoublyLinkedNode<string>::Node StringNode;
    
    StringNode n1( s1 );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( s4 );
    
    cout << "Test prepend:" << endl;
    
    n4.prepend( n1 );
    n4.prepend( n2 );
    n4.prepend( n3 );
    
    cout << "Three elements:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else
            cout << "<NULL>";
        
        cout << "," << pn->getValue()<< ",";
        
        if ( &pn->getNext() != &StringNode::NIL )
            cout << pn->getNext().getValue();
        else
            cout << "<NULL>";
        
        cout << ")" << endl;
    }
    
    n3.remove();
    
    cout << "Two elements:" << endl;
    
    for ( const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext() )
    {
        cout << "(";
        if ( &pn->getPrevious() != &StringNode::NIL )
            cout << pn->getPrevious().getValue();
        else 
            cout << "<NULL>"; 
        
        cout << "," << pn->getValue() << ","; 
        
        if ( &pn->getNext() != &StringNode::NIL ) 
            cout << pn->getNext().getValue(); 
        else 
            cout << "<NULL>"; 
        
        cout << ")" << endl; 
    } 
}

int main() {
    test1();
    test2();
    return 0;
}

