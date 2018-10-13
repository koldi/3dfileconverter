add_library(converter SHARED
  lib.cpp
)

target_include_directories(converter PUBLIC
  .
  include
)
