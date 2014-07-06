#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <cassert>
using namespace std;
#include "Fraction.h"

int main()
{
  Fraction f1(5);
  cout << "testing conversion constructor with f1 = \"3/5\";" << '\n';
  cout << "testing infix evaluation with f1 = \"3/5\";" << '\n';
  f1 = "3/5";
  cout << "f1 : " << f1 << '\n';
  assert(f1 == Fraction(3, 5));
  cout << "ok\n\n";

   return 0;
}
