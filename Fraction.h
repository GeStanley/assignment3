/*
 * Fraction.h
 *
 *  Created on: June 30, 2014
 *      Author: Geoffrey
 */
#ifndef FRACTION_H_
#define FRACTION_H_

#include <queue>
using namespace std;

class Fraction
{
public:
  //constructors
  Fraction();
  Fraction( long );
  Fraction( long, long );
  Fraction( const string & );
  Fraction( const char *);

  const string toString() const;
  const long getNumerator() const;
  const long getDenominator() const;

  void setNumerator( long );
  void setDenominator( long );

  Fraction & operator += (const Fraction & rhs);
  Fraction & operator -= (const Fraction & rhs);
  Fraction & operator *= (const Fraction & rhs);
  Fraction & operator /= (const Fraction & rhs);

  Fraction & operator++(); //++f
  Fraction operator++(int); //f++

  Fraction & operator--(); //--f
  Fraction operator--(int); //f--

  //function call operator
  string operator () (int);
private:

  long numerator;
  long denominator;

  static queue<string> Tokenize( const string & infixExpression );
  static Fraction evaluateInfix( queue<string> & infixQueue );

  static int precedence( string );
  void normalize();
  static long gcd( long, long );
};

  //*********
  //NON-MEMBER OPERATORS
  //unary operators
  Fraction operator+ ( const Fraction & rhs );
  Fraction operator- ( const Fraction & rhs );
  //binary operators
  Fraction operator+ (const Fraction &, const Fraction &);
  Fraction operator- (const Fraction &, const Fraction &);
  Fraction operator* (const Fraction& lhs, const Fraction& rhs);
  Fraction operator/ (const Fraction& lhs, const Fraction& rhs);

  //main logical operators
  //main logical operators
  bool operator == ( const Fraction & lhs, const Fraction & rhs );
  bool operator < (const Fraction &lhs, const Fraction & rhs);
  //secondary logical operators, deduced from above
  bool operator != (const Fraction &lhs, const Fraction & rhs);
  bool operator <= (const Fraction &lhs, const Fraction & rhs);
  bool operator > (const Fraction &lhs, const Fraction & rhs);
  bool operator >= (const Fraction &lhs, const Fraction & rhs);

  //insertion operator >>
  //istream & operator >> ( istream &, Fraction &);

  //extraction operator <<
  ostream & operator << ( ostream &, const Fraction & );
#endif /* WORDLIST_H_ */
