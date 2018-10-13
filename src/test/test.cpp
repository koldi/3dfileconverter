#include "catch2.hpp"
#include "lib.h"

TEST_CASE("Lib", "Test")
{
  A a;
  a.a = 7;
  REQUIRE(a.foo() == 7);
}
