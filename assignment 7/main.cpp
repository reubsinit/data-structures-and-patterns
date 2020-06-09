/*
 * main.cpp
 */

#include "DynamicStack.h"
#include "DynamicStackIterator.h"
#include "DynamicQueue.h"
#include "DynamicQueueIterator.h"

#include <iostream>
#include <string>

using namespace std;

void test1()
{
	DynamicStack<int> lStack;

	lStack.push( 1 );
	lStack.push( 2 );
	lStack.push( 3 );
	lStack.push( 4 );
	lStack.push( 5 );
	lStack.push( 6 );

	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	cout << "size: " << lStack.size() << endl;
	cout << "is empty: " << (lStack.isEmpty() ? "T" : "F" ) << endl;
	lStack.pop();
	lStack.pop();
	cout << "top: " << lStack.top() << endl;
	lStack.pop();
	cout << "is empty: " << (lStack.isEmpty() ? "T" : "F" ) << endl;
}

void test2()
{
	DynamicStack<string> lStack;

	string s1( "One" );
	string s2( "Two" );
	string s3( "Three" );
	string s4( "Four" );
	string s5( "Five" );
	string s6( "Six" );

	lStack.push( s1 );
	lStack.push( s2 );
	lStack.push( s3 );
	lStack.push( s4 );
	lStack.push( s5 );
	lStack.push( s6 );

	cout << "Traverse elements" << endl;

	for ( DynamicStackIterator<string> iter = DynamicStackIterator<string>( lStack ); iter != iter.end(); iter++ )
	{
		cout << "value: " << *iter << endl;
	}
}

void test3()
{
	DynamicQueue<int> lQueue;

	lQueue.enqueue( 1 );
	lQueue.enqueue( 2 );
	lQueue.enqueue( 3 );
	lQueue.enqueue( 4 );
	lQueue.enqueue( 5 );
	lQueue.enqueue( 6 );

	cout << "Queue elements:" << endl;

	while ( !lQueue.isEmpty() )
	{
		cout << "value: " << lQueue.dequeue() << endl;
	}
}

void test4()
{
	DynamicQueue<string> lQueue;

	string s1( "One" );
	string s2( "Two" );
	string s3( "Three" );
	string s4( "Four" );
	string s5( "Five" );
	string s6( "Six" );

	lQueue.enqueue( s1 );
	lQueue.enqueue( s2 );
	lQueue.enqueue( s3 );
	lQueue.enqueue( s4 );
	lQueue.enqueue( s5 );
	lQueue.enqueue( s6 );

	cout << "Traverse queue elements" << endl;

	for ( DynamicQueueIterator<string> iter = DynamicQueueIterator<string>( lQueue ); iter != iter.end(); iter++ )
	{
		cout << "value: " << *iter++ << endl;
	}
}

int main()
{
	cout << "Test 1: " << endl;

	test1();

	cout << "Test 2: " << endl;

	test2();

	cout << "Test 3: " << endl;

	test3();

	cout << "Test 4: " << endl;

	test4();

	return 0;
}
