#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "FileWriter.h"

int main ()
{
  auto f = FileReader::ReadFile("/Users/gyorgykatona/git/3dfileconverter/input/input.obj");
  FileWriter::WriteFile("/Users/gyorgykatona/git/3dfileconverter/input/input.stl", f);

  return 0;
}