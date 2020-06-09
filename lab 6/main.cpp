//
//  main.cpp
//  Lab6
//
//  Created by Reuben Wilson on 9/05/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
    
#if true
	// Step 1:
	// implement:
	// - default constructor
	// - getIterator
    
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
    
#if true    // disable with false
	// Step 2:
	// implement:
	// - push_back
    
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
    
#if true    // disable with false
	// Step 3:
	// implement:
	// - remove
    
	lList.remove( s3 );
	lList.remove( s1 );
	lList.remove( s6 );
    
	// iterate from the top
	cout << "Top to bottom: " << lList.size() << " elements" << endl;
	for ( List<string>::Iterator iter = lList.getIterator();
         iter != iter.rightEnd(); iter++ )
	{
		cout << "A list element: " << *iter << endl;
	}
    
#endif
    
#if true    // disable with false
	// Step 4:
	// implement:
	// - operator[]
    
	cout << "Element at index 2: " << lList[2] << endl;
    
#endif
    
#if true
    // Step 5: copy control
    
    List<string> copy( lList );
    
    // iterate from the top
    cout << "A - Top to bottom: " << copy.size() << " elements" << endl;
    
    for ( List<string>::Iterator iter = copy.getIterator();
         iter != iter.rightEnd(); iter++ )
    {
        cout << "A list element: " << *iter << endl;
    }
    
    // override list
    lList = copy;
    
    lList.push_front( s6 );
    lList.push_back( s1 );
    
    // iterate from the top
    cout << "B - Bottom to top: " << lList.size() << " elements" << endl;
    
    for ( List<string>::Iterator iter = lList.getIterator().last();
         iter != iter.leftEnd(); iter-- )
    {
        cout << "A list element: " << *iter << endl;
    }
    
#endif
    
	return 0;
}

