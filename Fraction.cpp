/*
 * Fraction.cpp
 *
 *  Created on: June 30, 2014
 *      Author: Geoffrey
 */
#include <iostream>
using namespace std;
#include "Fraction.h"

Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}

Fraction::Fraction( long numerator)
{
  this->numerator = numerator;
  denominator = 1;
}

Fraction::Fraction( long numerator, long denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

bool operator == (const Fraction &lhs, const Fraction & rhs)
{
  if(lhs.numerator==rhs.numerator && lhs.denominator==rhs.denominator)
    return true;
  else
    return false;
}

ostream & operator << (ostream &output, const Fraction &fraction)
{
    output << fraction.numerator << "/" <<
        fraction.denominator ;
    return output;
}
