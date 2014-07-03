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

bool operator == ( const Fraction &lhs, const Fraction & rhs )
{
  if(lhs.getNumerator()==rhs.getNumerator() && 
	lhs.getDenominator()==rhs.getDenominator())
    return true;
  else
    return false;
}

ostream & operator << ( ostream &output, const Fraction &fraction )
{
   return output << fraction.toString();
}
