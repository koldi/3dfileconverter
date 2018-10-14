#include <iostream>
#include "FileReader.h"


int main ()
{
  auto f = FileReader::ReadFile("/Users/gyorgykatona/git/3dfileconverter/input/input.obj");
  for(auto k : f)
  {
    std::cout << "Material name: " << k.name_;
    for(auto t : k.faces_)
    {
      t.ToString();
    }
  }
  return 0;
}