#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "FileWriter.h"

int main (int argc, char *argv[])
{
  if (argc < 3) {
      std::cout << "Usage: first parameter is OBJ file, second is STL file\n";
      return 1;
  }

  auto f = FileReader::ReadFile(argv[1]);
  FileWriter::WriteFile(argv[2], f);

  return 0;
}