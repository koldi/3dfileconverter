#include <iostream>
#include "lib.h"
#include "FileReader.h"


int main ()
{
  auto f = FileReader::CreateFileReader("/Users/gyorgykatona/git/3dfileconverter/input/input.obj");
  for(auto k : f->faces_)
  {
      std::cout << "valami" << std::endl;
  }
  return 0;
}