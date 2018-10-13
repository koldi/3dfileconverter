add_library(converter SHARED
  FileReader.cpp
  OBJParser.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
