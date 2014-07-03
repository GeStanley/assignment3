/*
 * Fraction.cpp
 *
 *  Created on: June 30, 2014
 *      Author: Geoffrey
 */
#include <iostream>
#include <string>
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

  simplify();
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
    //output << fraction.numerator << "/" <<
    //   fraction.denominator ;
    //return output;
   return output << fraction.toString();
}
const string Fraction::toString() const
{
    string result;
    result += numerator;
    result += "/";
    result += denominator;

    cout << "the string created is : " << result << endl;

    return result;
}

void Fraction::simplify()
{
  long gcm = findGreatestCommonDenominator( numerator, denominator);
  
  numerator /= gcm ;
  denominator /= gcm;
}

long Fraction::findGreatestCommonDenominator( long numer, long denom)
{
  return (denom == 0) ? numer : findGreatestCommonDenominator( denom, numer % denom);
}
