add_library(converter SHARED
  FileReader.cpp
  OBJParser.cpp
  STLParser.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
