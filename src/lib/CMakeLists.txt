add_library(converter SHARED
  FileReader.cpp
  FileWriter.cpp
  OBJParser.cpp
  STLParser.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
