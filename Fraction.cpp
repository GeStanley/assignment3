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
  //cout << "const string &infix constructor" << endl;

  queue<string> myQueue = Tokenize(infix);

  *this = evaluateInfix(myQueue);

  normalize();
}

Fraction::Fraction( const char *characters)
{
  //cout << "const char *characters constructor" << endl;
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

  //cout << "entered evaluate infix" << endl;

  while(!infixQueue.empty())
    {
      string token = infixQueue.front();
      infixQueue.pop();

      if(token == "+" ||
        token == "-" ||
        token == "*" ||
        token == "/")
        {
	  while(!operators.empty() && 
                precedence(infixQueue.front())>precedence(token))
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
        {
          while(!operators.empty() && token != "(")
            {
              operands.push(evaluateOperation(operators, operands));
            }
        }
      else
        {
          string::size_type sz;
          long number = stol(token, &sz);
          operands.push(Fraction(number));
        }
    }


  while(!operators.empty())
    {
      operands.push(evaluateOperation(operators, operands));
    }

  Fraction result = operands.top();
  operands.pop();

  return result;
}

Fraction Fraction::evaluateOperation( stack<string> & operators, stack<Fraction> & operands)
{
  Fraction rhs = operands.top();
  operands.pop();
  Fraction lhs = operands.top();
  operands.pop();

  string oper = operators.top();
  operators.pop();

  lhs.normalize();
  rhs.normalize();
  cout << "evaluating : " << lhs << oper << rhs << endl;

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
