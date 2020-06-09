//
//  main.cpp
//  Lab1
//
//  Created by Reuben Wilson on 6/03/2014.
//  Copyright (c) 2014 Reuben Wilson. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    cout << argc << endl;
    char name[50];
    cin >> name;
    cout << name << endl;
    return 0;
}

