add_executable(test_runner TestBasic.cpp)
target_link_libraries(test_runner mylib gtest gtest_main)
add_test(NAME MyTests COMMAND test_runner)