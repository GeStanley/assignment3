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

const string Fraction::toString() const
{
    return to_string(numerator) + "/" + to_string(denominator);
}

const long Fraction::getNumerator() const
{
  return numerator;
}

const long Fraction::getDenominator() const
{
  return denominator;
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

//********************* NON-MEMBER FUNCTIONS *************************//

Fraction operator + (const Fraction & rhs)
{
  return rhs;
}

Fraction operator - (const Fraction & rhs)
{
  Fraction temp(-rhs.getNumerator(), rhs.getDenominator());
  return temp;
}

bool operator == (const Fraction &lhs, const Fraction & rhs)
{
  if(lhs.getNumerator()==rhs.getNumerator() && 
	lhs.getDenominator()==rhs.getDenominator())
    return true;
  else
    return false;
}

ostream & operator << (ostream &output, const Fraction &fraction)
{
   return output << fraction.toString();
}
