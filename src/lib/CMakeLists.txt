add_library(converter SHARED
  FileReader.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
