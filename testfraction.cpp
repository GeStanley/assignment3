#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;
#include "Fraction.h"

int main()
{
   cout << "Test Fraction and Fractional Computation" << '\n';
   cout << "----------------------------------------\n\n";

   cout << "testing default ctor with Fraction f0;" << '\n';
   Fraction f0;         // test default ctor
   cout << f0 << '\n';


   cout << "testing 1-arg ctor with Fraction f1(5);" << '\n';
   Fraction f1(5);      // test 1 arg ctor
   cout << f1 << "\n\n";

   cout << "testing == comparator to int;" << '\n';
   assert(f0 == 0);   // test fraction == integer
   cout << "does f0 equal 0;" << '\n';
   f0==0 ? cout << "true" << endl : cout << "false" << endl;
   cout << "does f1 equal 0;" << '\n';
   f1==0 ? cout << "true" << endl : cout << "false" << endl;
   cout << "does f1 equal 5;" << '\n';
   f1==5 ? cout << "true" << endl : cout << "false" << endl;

   cout << "testing == comparator to another fraction;" << '\n';
   Fraction f2(5);
   assert(f2 == f1);
   cout << "does f2 equal f1;" << '\n';
   f2==f1 ? cout << "true" << endl : cout << "false" << endl;
   cout << "does f2 equal f0;" << '\n';
   f2==f0 ? cout << "true" << endl : cout << "false" << endl;


   return 0;
}
