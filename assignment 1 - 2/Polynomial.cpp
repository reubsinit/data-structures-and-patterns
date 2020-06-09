//  Polynomial.cpp

#include <iostream>
#include <math.h>

#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
    fDegree = 0;
    for (int i = 0; i < MAX_DEGREE; i++)
    {
        fCoeffs[i] = 0.0;
    }
}

Polynomial Polynomial::operator*(const Polynomial& aRight)const
{
    Polynomial result;
    result.fDegree = aRight.fDegree + fDegree;
    for (int i = 0; i <= aRight.fDegree; i++)
    {
        for (int j = 0; j <= fDegree; j++)
        {
            result.fCoeffs[j + i] += fCoeffs[j] * aRight.fCoeffs[i];
        }
    }
    return result;
}

double Polynomial::calculate(double aX) const
{
    double result = 0.0;
    for (int i = 0; i <= fDegree; i++)
    {
        result += pow(aX, i) * fCoeffs[i];
    }
    return result;
}

Polynomial Polynomial::indefiniteIntegral() const
{
    Polynomial result;
    result.fDegree = fDegree + 1;
    for (int i = result.fDegree; i > 0; i--)
    {
        result.fCoeffs[i] = fCoeffs[i - 1]/i;
    }
    return result;
}

double Polynomial::definiteIntegral(double aXLow, double aXHigh) const
{
    Polynomial result = indefiniteIntegral();
    return result.calculate(aXHigh) - result.calculate(aXLow);
}

istream& operator>>(istream& aIStream, Polynomial& aObject)
{
    cout << "Please specify the degree of your Polynomial: " << endl;
    aIStream >> aObject.fDegree;
    for (int i = 0; i <= aObject.fDegree; i++)
    {
        cout << "Enter coefficient number " << i + 1 << ": " << endl;
        aIStream >> aObject.fCoeffs[i];
    }
    return aIStream;
}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject)
{
    for (int i = 0; i <= aObject.fDegree; i++)
    {
        if (i > aObject.fDegree - 1)
        {
            aOStream << aObject.fCoeffs[i] << "x^" << i;
        }
        else
        {
            aOStream << aObject.fCoeffs[i] << "x^" << i << " + ";
        }
    }
    return aOStream;
}

