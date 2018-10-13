add_executable(test_3dfileconverter
  test_main.cpp
  test.cpp
)

target_link_libraries(test_3dfileconverter
  converter
)

include_directories ("${PROJECT_SOURCE_DIR}/lib/include")

add_test(
  NAME    3DFileConverter
  COMMAND test_3dfileconverter
)
