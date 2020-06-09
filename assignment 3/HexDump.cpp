//
//  HexDump.cpp
//  Assignment 3
//
//  Created by Reuben Wilson on 9/04/2014.
//  Copyright (c) 2014 BitNak. All rights reserved.
//

#include <iomanip>
#include "HexDump.h"

using namespace std;

bool HexDump::open(const std::string& aInputFileName)
{
    fInput.open(aInputFileName, ifstream::binary);
    if (!fInput.good())
    {
        cerr << "Cannot open input file: " << aInputFileName << endl;
        return false;
    }
    return true;
}

void HexDump::close()
{
    fInput.close();
}

void HexDump::processInput()
{
    unsigned char lInput[16];
    int fileAddress = 0;
    int lLineLength = BYTE_SIZE * 3 + 2;
    int lCurrentDataLength = 0;
    
    
    while (fInput.good())
    {
        cout << setw(8) << setfill('0') << uppercase << hex << fileAddress << ": ";
        lCurrentDataLength = lLineLength;
        for (int i = 0; i < BYTE_SIZE; i++)
        {
            lInput[i] = fInput.get();
            if (fInput.good())
            {
                cout << setw(2) << setfill('0') << uppercase << hex << int(lInput[i]) << " ";
                if (i == BYTE_SIZE/2 - 1)
                {
                    cout << "| ";
                }
            }
            else
            {
                lCurrentDataLength = i * 3;
                if (i > BYTE_SIZE / 2 - 1)
                {
                    lCurrentDataLength+=2;
                }
                break;
            }
        }
        if (lCurrentDataLength < lLineLength)
        {
            cout << setw(lLineLength - lCurrentDataLength + 1) << setfill(' ');
        }
        for (int i = 0; i < lCurrentDataLength / 3; i++)
        {
            if (lInput[i] < '!' || lInput[i] > '~')
            {
                cout << ".";
            }
            else
            {
                cout << lInput[i];
            }
        }
        cout << endl;
        fileAddress += BYTE_SIZE;
    }
}
