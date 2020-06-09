//
//  main.cpp
//  Assignment 6
//
//  Created by Reuben Wilson on 30/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <string>
#include "List.h"

#define true 1
#define false 0

using namespace std;

int main()
{
    
#if true
	string s1( "AAAA" );
	string s2( "BBBB" );
	string s3( "CCCC" );
	string s4( "DDDD" );
    
	List<string> lList;
    
	lList.push_front( s4 );
	lList.push_front( s3 );
	lList.push_front( s2 );
	lList.push_front( s1 );
    
	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator();
         iter != iter.rightEnd(); iter++ )
	{
		cout << "A list element: " << *iter << endl;
	}
    
#endif
    
#if true
	string s5( "EEEE" );
	string s6( "FFFF" );
    
	lList.push_back( s5 );
	lList.push_back( s6 );
    
	// iterate from the last
	cout << "Bottom to top: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator().last();
         iter != iter.leftEnd(); iter-- )
	{
		cout << "A list element: " << *iter << endl;
	}
    
#endif
    
#if true
	lList.remove( s6 );
    
	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator();
         iter != iter.rightEnd(); iter++ )
	{
		cout << "A list element: " << *iter << endl;
	}
    
#endif
    
#if true
	cout << "Element at index 2: " << lList[2] << endl;
    
#endif
    
	return 0;
}

