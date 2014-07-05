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

  normalize();
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

queue<string> Fraction::Tokenize( const string & infixExpression )
{
  queue<string> tokens;
  string currentToken;

  for( char currentChar : infixExpression )
  {
    //check to see if current char is a digit
    if(currentChar >= 48 && currentChar <= 57 )
      currentToken += currentChar;
    //if it's a space do nothing
    else if(currentChar == ' '){}
    else{
      //if a string representing a digit was
      //parsed push it to the stack
      if(currentToken!="")
        tokens.push(currentToken);

      string operation ="";
      operation += currentChar;
      tokens.push(operation);

      //reset currentToken values
      currentToken="";
    }
  }
  //if the last char of the string was a digit
  //push it to the stack
  if(currentToken!="")
    tokens.push(currentToken);

  return tokens;
}

Fraction evaluateInfix( queue<string> & infixQueue )
{
  stack<Fraction> operands;
  stack<string> operators;

  while(!infixQueue.empty())
    {
      if(infixQueue.front()=="+" ||
        infixQueue.front()=="-" ||
        infixQueue.front()=="*" ||
        infixQueue.front()=="/")
        {

        }
      else if(infixQueue.front()=="(")
        {
        operators.push(infixQueue.front());
        }
      else if(infixQueue.front()==")")
        {

        }
      else if(false)

      infixQueue.pop();
    }
  //TODO IMPLEMENT THIS FUNCTION
}

void Fraction::normalize()
{
  long divisor = gcd( numerator, denominator );

  numerator /= divisor;
  denominator /= divisor;
}

long Fraction::gcd( long numer, long denom )
{
  return (denom == 0) ? numer : gcd( denom, numer % denom );
}

Fraction & Fraction::operator += (const Fraction & rhs)
{
  this->numerator = this->numerator * rhs.getDenominator()
                   + rhs.getNumerator() * this->denominator;

  this->denominator *= rhs.getDenominator();

  this->normalize();

  return *this;
}

Fraction & Fraction::operator -= (const Fraction & rhs)
{
  this->numerator = this->numerator * rhs.getDenominator()
                   - rhs.getNumerator() * this->denominator;

  this->denominator *= rhs.getDenominator();

  this->normalize();

  return *this;
}

Fraction & Fraction::operator *= (const Fraction & rhs)
{
  this->numerator *= rhs.getNumerator();

  this->denominator *= rhs.getDenominator();

  this->normalize();

  return *this;
}

Fraction & Fraction::operator /= (const Fraction & rhs)
{
  this->numerator *= rhs.getDenominator();

  this->denominator *= rhs.getNumerator();

  this->normalize();

  return *this;
}

Fraction & Fraction::operator++() //++f
{
  numerator += denominator;

  normalize();

  return *this;
}

Fraction Fraction::operator++(int) //f++
{
  Fraction temp(numerator, denominator);

  numerator += denominator;

  normalize();

  return temp;
}

Fraction & Fraction::operator--() //++f
{
  numerator -= denominator;

  normalize();

  return *this;
}

Fraction Fraction::operator--(int) //f++
{
  Fraction temp(numerator, denominator);

  numerator -= denominator;

  normalize();

  return temp;
}

//********************* NON-MEMBER OPERATORS *********************//

Fraction operator+ ( const Fraction & rhs )
{
  return rhs;
}

Fraction operator- ( const Fraction & rhs )
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

Fraction operator* (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp *= rhs;
  return temp;
}

Fraction operator/ (const Fraction& lhs, const Fraction& rhs)
{
  Fraction temp(lhs);
  temp /= rhs;
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

  long left = lhs.getNumerator() * rhs.getDenominator();
  long right = rhs.getNumerator() * lhs.getDenominator();

  if(left<right) return true;
  else return false;

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

//istream & operator >> (istream &input, Fraction &fraction)
//{
    //input >> must finish this to extract numerator
    //input.ignore(); //ignore the /
    //input >> must finish this to extract denominator
    //pass numer and denom to fraction.
    //return input;
//}

ostream & operator << ( ostream &output, const Fraction &fraction )
{
   return output << fraction.toString();
}
