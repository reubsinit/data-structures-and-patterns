//
//  main.cpp
//  Lab7
//
//  Created by Reuben Wilson on 16/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include "List.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	List<string> l;
	string s1( "One" );
	string s2( "Two" );
	string s3( "Three" );
	string s4( "Four" );
    
	l.add( s1 );
	l.add( s2 );
	l.add( s3 );
	l.add( s4 );
    
	cout << "The list:" << endl;
    
	for ( List<string>::ListIterator iter = l.iterator(); iter != iter.end(); iter++ )
		cout << *iter << endl;
    
	List<string> copy = l;
    
	cout << "The copy:" << endl;
    
	for ( List<string>::ListIterator iter = copy.iterator(); iter != iter.end(); iter++ )
		cout << *iter << endl;
    
	return 0;
}

