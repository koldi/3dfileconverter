add_library(converter SHARED
  lib.cpp
  FileReader.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
