add_executable(3DFileConverter 
  main.cpp
)

target_link_libraries(3DFileConverter
  converter
)

include_directories ("${PROJECT_SOURCE_DIR}/lib/include")

target_include_directories(3DFileConverter PRIVATE
  .
)
