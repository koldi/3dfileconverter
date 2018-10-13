add_executable(test_3dfileconverter
  test_main.cpp
  test.cpp
)

add_test(
  NAME    3DFileConverter
  COMMAND test_3dfileconverter
)
