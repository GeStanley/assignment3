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


   Fraction f3(500,1000);
   cout << "does f3 equal 1/2" << '\n';
   f3.toString() == "1/2" ? cout << "true" << endl : cout << "false" << endl;

   Fraction f4(17,3);
   cout << "does f4 equal 17/3" << '\n';
   f4.toString() == "17/3" ? cout << "true" << endl : cout << "false" << endl;

   Fraction f5(462,1071);
   cout << "does f5 equal 22/51" << '\n';
   f5.toString() == "22/51" ? cout << "true" << endl : cout << "false" << endl;



   Fraction test("(9-1 + 2)*(8-3)+6/2");
   return 0;
}
