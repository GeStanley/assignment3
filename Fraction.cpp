/*
 * Fraction.cpp
 *
 *  Created on: June 30, 2014
 *      Author: Geoffrey
 */
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
#include "Fraction.h"

Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}

Fraction::Fraction( long numerator )
{
  this->numerator = numerator;
  denominator = 1;
}

Fraction::Fraction( long numerator, long denominator )
{
  this->numerator = numerator;
  this->denominator = denominator;

  normalize();
}

Fraction::Fraction( string infix )
{
  Fraction::Tokenize(infix);
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

void Fraction::setNumerator( long numer )
{
  numerator = numer;
}

void Fraction::setDenominator( long denom )
{
  (denom == 0) ?  : denominator = denom;
  //TODO THROW EXCEPTION

}

static queue<string> Fraction::Tokenize( const string & infixExpression )
{
  queue<string> tokens;

  for( char currentChar : infixExpression )
  {
    cout << currentChar << endl;
  }


  tokens.push("nothing");
  return tokens;
}

static Fraction evaluateInfix( queue<string> & infixQueue )
{

}

void Fraction::normalize()
{
  long gcm = gcd( numerator, denominator );

  numerator /= gcm;
  denominator /= gcm;
}

long Fraction::gcd( long numer, long denom )
{
  return (denom == 0) ? numer : gcd( denom, numer % denom );
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

//********************* NON-MEMBER FUNCTIONS *********************//

Fraction operator + ( const Fraction & rhs )
{
  return rhs;
}

Fraction operator - ( const Fraction & rhs )
{
  Fraction temp(-rhs.getNumerator(), rhs.getDenominator());
  return temp;
}

Fraction operator+ (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp += rhs;
  return temp;
}

Fraction operator- (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp -= rhs;
  return temp;
}

bool operator == ( const Fraction &lhs, const Fraction & rhs )
{
  if(lhs.getNumerator()==rhs.getNumerator() &&
	lhs.getDenominator()==rhs.getDenominator())
    return true;
  else
    return false;
}

bool operator < (const Fraction &lhs, const Fraction &rhs)
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

bool operator != (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs == rhs) return false;

  return true;
}

bool operator <= (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs == rhs || lhs < rhs)
    return true;

  return false;
}

bool operator > (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs < rhs) return false;

  if(lhs == rhs) return false;

  return true;
}

bool operator >= (const Fraction &lhs, const Fraction &rhs)
{
  if(lhs < rhs) return false;

  return true;
}

istream & operator >> (istream &input, Fraction &fraction)
{
    //input >> must finish this to extract numerator
    input.ignore(); //ignore the /
    //input >> must finish this to extract denominator
    //pass numer and denom to fraction.
    return input;
}

ostream & operator << ( ostream &output, const Fraction &fraction )
{
   return output << fraction.toString();
}
