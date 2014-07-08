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
#include <exception>
using namespace std;
#include "Fraction.h"

Fraction::Fraction()
{
  setNumerator(0);
  setDenominator(1);
}

Fraction::Fraction( long numerator )
{
  setNumerator(numerator);
  setDenominator(1);
}

Fraction::Fraction( long numerator, long denominator )
{
  setNumerator(numerator);
  setDenominator(denominator);

  normalize();
}

Fraction::Fraction( const string &infix )
{
  queue<string> myQueue = Tokenize(infix);

  *this = evaluateInfix(myQueue);

  normalize();
}

Fraction::Fraction( const char *characters)
{
  string temp;
  temp+= characters;

  queue<string> myQueue = Tokenize(temp);

  *this = evaluateInfix(myQueue);

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

void Fraction::setFraction( const string &infix)
{
  queue<string> myQueue = Tokenize(infix);

  *this = evaluateInfix(myQueue);

  normalize();
}

void Fraction::setNumerator( long numer )
{
  numerator = numer;
}

void Fraction::setDenominator( long denom )
{
  (denom == 0) ? throw "Division by zero" : denominator = denom;
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
      if(currentToken != "")
        tokens.push(currentToken);

      string operation = "";
      operation += currentChar;
      tokens.push(operation);

      //reset currentToken values
      currentToken = "";
    }
  }
  //if the last char of the string was a digit
  //push it to the stack
  if(currentToken != "")
    tokens.push(currentToken);

  return tokens;
}

Fraction Fraction::evaluateInfix( queue<string> & infixQueue )
{
  stack<Fraction> operands;
  stack<string> operators;

  while(!infixQueue.empty())
    {//get the next token from the queue
      string token = infixQueue.front();
      infixQueue.pop();

      if(token == "+" ||
        token == "-" ||
        token == "*" ||
        token == "/")
        {//prioritize operations with higher precedence
	        while(!operators.empty() &&
            precedence(token) <= precedence(operators.top()))
            {
              operands.push(evaluateOperation(operators, operands));
            }

          operators.push(token);
        }
      else if(token == "(")
        {
          operators.push(token);
        }
      else if(token == ")")
        { //evaluate all operations between the parenthesis
          while(operators.top() != "(")
            {
              operands.push(evaluateOperation(operators, operands));
            }
          //remove the opening parenthesis
          operators.pop();
        }
      else
        {//convert string to long
          string::size_type sz;
          long number = stol(token, &sz);

          //and use the long to create a Fraction
          operands.push(Fraction(number));
        }
    }

  //complete the remaining operations
  while(!operators.empty())
    {
      operands.push(evaluateOperation(operators, operands));
    }
  //retrieve the result of the operation from the stack
  Fraction result = operands.top();
  operands.pop();

  return result;
}

Fraction Fraction::evaluateOperation( stack<string> & operators, stack<Fraction> & operands)
{
  //pop two Fractions from the stack
  Fraction rhs = operands.top();
  operands.pop();
  Fraction lhs = operands.top();
  operands.pop();

  //pop the operand from the stack
  string oper = operators.top();
  operators.pop();

  lhs.normalize();
  rhs.normalize();

  //perform the operation as indicated by the operand
  if(oper=="+")
    return lhs + rhs;

  if(oper=="-")
    return lhs - rhs;

  if(oper=="*")
    return lhs * rhs;

  if(oper=="/")
    return lhs / rhs;
}

int Fraction::precedence( string oper )
{
  if(oper=="*" || oper=="/")
    return 2;

  if(oper=="+" || oper=="-")
    return 1;

  if(oper=="(")
    return 0;
}

void Fraction::normalize()
{//find the greatest common denominator
  long divisor = gcd( numerator, denominator );

  //use it to simplify the fraction.
  numerator /= divisor;
  denominator /= divisor;
}

long Fraction::gcd( long numer, long denom )
{//recursively determine the greatest common denominator
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

string Fraction::operator() (int)
{
  return toString();
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

istream & operator >> (istream &input, Fraction &fraction)
{
    string infix;
    input >> infix;
    fraction.setFraction(infix);
    return input;
}

ostream & operator << ( ostream &output, const Fraction &fraction )
{
   return output << fraction.toString();
}
