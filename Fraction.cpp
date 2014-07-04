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

Fraction::Fraction( const string & input)
{
  string::size_type sz;
  Fraction(stol(input, &sz));
}

Fraction Fraction::operator+ (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp += rhs;
  return temp;
}

Fraction Fraction::operator- (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp -= rhs;
  return temp;
}

Fraction & Fraction::operator += (const Fraction & rhs)
{
  this->numerator = this->numerator * rhs.denominator
                   + rhs.numerator * this->denominator;
  this->denominator *= rhs.denominator;

  return *this;
}

Fraction & Fraction::operator -= (const Fraction & rhs)
{
  this->numerator = this->numerator * rhs.denominator
                   - rhs.numerator * this->denominator;
  this->denominator *= rhs.denominator;

  return *this;
}

bool operator == (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs.numerator==rhs.numerator &&
    lhs.denominator==rhs.denominator)
    return true;
  else
    return false;
}

bool Fraction::operator < (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs.numerator==rhs.numerator)
  {
    if(lhs.denominator>rhs.denominator)
      return true;
    else
      return false;
  }
  else
    return false;
}

bool Fraction::operator != (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs == rhs) return false;

  return true;
}

bool Fraction::operator <= (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs == rhs || lhs < rhs)
    return true;

  return false;
}

bool Fraction::operator > (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs < rhs) return false;

  if(lhs == rhs) return false;

  return true;
}

bool Fraction::operator >= (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs < rhs) return false;

  return true;
}

istream & operator << (istream &input, Fraction &fraction)
{
    //input >> must finish this to extract numerator
    input.ignore(); //ignore the /
    //input >> must finish this to extract denominator
    //pass numer and denom to fraction.
    return input;
}

ostream & operator << (ostream &output, const Fraction &fraction)
{
    output << fraction.numerator << "/" <<
        fraction.denominator ;
    return output;
}
