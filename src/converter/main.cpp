#include <iostream>
#include "FileReader.h"


int main ()
{
  auto f = FileReader::CreateFileReader("/Users/gyorgykatona/git/3dfileconverter/input/input.obj");
  for(auto k : f->faces_)
  {
    k.ToString();
  }
  return 0;
}