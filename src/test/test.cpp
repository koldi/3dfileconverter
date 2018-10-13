#include "catch2.hpp"


int add(int a, int b)
{
    return a + b;
}

TEST_CASE("Add", "Integers")
{
  REQUIRE(add(1,2) == 3);
}
