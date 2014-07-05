#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

int main()
{

  queue <string> myQueue;

  myQueue.push("hello");
  myQueue.push("world");


  cout << myQueue.front() << endl;

   return 0;
}
