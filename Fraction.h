/*
 * Fraction.h
 *
 *  Created on: June 30, 2014
 *      Author: Geoffrey
 */
#ifndef FRACTION_H_
#define FRACTION_H_
using namespace std;

class Fraction
{
public:
  //constructors
  Fraction();
  Fraction( long);
  Fraction( long, long);
  Fraction( const string &);

  //unary operators
  //Fraction operator+ (const Fraction & rhs);
  //Fraction operator- (const Fraction & rhs);
  //binary operators
  Fraction operator+ (const Fraction &, const Fraction &);
  Fraction operator- (const Fraction &, const Fraction &);
  //Fraction operator* (const Fraction& lhs, const Fraction& rhs);
  //Fraction operator/ (const Fraction& lhs, const Fraction& rhs);

  Fraction & operator += (const Fraction &);
  Fraction & operator -= (const Fraction &);
  //Fraction & Fraction::operator *= (const Fraction & rhs);
  //Fraction & Fraction::operator /= (const Fraction & rhs);

  //main logical operators
  friend bool operator == (const Fraction &, const Fraction &);
  bool operator < (const Fraction &, const Fraction &);
  //secondary logical operators, deduced from above
  bool operator != (const Fraction &lhs, const Fraction & rhs);
  bool operator <= (const Fraction &lhs, const Fraction & rhs);
  bool operator > (const Fraction &lhs, const Fraction & rhs);
  bool operator >= (const Fraction &lhs, const Fraction & rhs);

  //Fraction & Fraction::operator++(); //++f
  //Fraction Fraction::operator++(int); //f++

  //function call operator
  //String operator () ();

  //insertion operator >>
  friend istream & operator << ( istream &, Fraction &);

  //extraction operator <<
  friend ostream & operator << ( ostream &, const Fraction &);

private:
  long numerator;
  long denominator;
};

#endif /* WORDLIST_H_ */
