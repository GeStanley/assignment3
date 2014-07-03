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
  //Fraction( std::string);
  
  const string toString() const;
  const long getNumerator() const;
  const long getDenominator() const;

private:
  
  
  void simplify();
  long findGreatestCommonDenominator( long, long);
	
  long numerator;
  long denominator;
};

  //*********
  //NON-MEMBER OPERATORS

  //unary operators
  Fraction operator+ (const Fraction & );
  Fraction operator- (const Fraction & );
  //binary operators
  //Fraction operator+ (const Fraction& lhs, const Fraction& rhs);
  //Fraction operator- (const Fraction& lhs, const Fraction& rhs);
  //Fraction operator* (const Fraction& lhs, const Fraction& rhs);
  //Fraction operator/ (const Fraction& lhs, const Fraction& rhs);

  //Fraction & Fraction::operator += (const Fraction & rhs);
  //Fraction & Fraction::operator -= (const Fraction & rhs);
  //Fraction & Fraction::operator *= (const Fraction & rhs);
  //Fraction & Fraction::operator /= (const Fraction & rhs);

  //main logical operators
  bool operator == (const Fraction &, const Fraction &);
  //bool operator < (const Fraction &lhs, const Fraction & rhs);
  //secondary logical operators, deduced from above
  //bool operator != (const Fraction &lhs, const Fraction & rhs);
  //bool operator <= (const Fraction &lhs, const Fraction & rhs);
  //bool operator > (const Fraction &lhs, const Fraction & rhs);
  //bool operator >= (const Fraction &lhs, const Fraction & rhs);

  //Fraction & Fraction::operator++(); //++f
  //Fraction Fraction::operator++(int); //f++

  //function call operator
  //String operator () ();

  //insertion operator >>

  //extraction operator <<
  ostream & operator << ( ostream &, const Fraction &);
#endif /* WORDLIST_H_ */
