#include <iostream>
#include "lib.h"

int main ()
{
  A a;
  a.a = 6;
  std::cout << a.foo() << std::endl;
  return 0;
}