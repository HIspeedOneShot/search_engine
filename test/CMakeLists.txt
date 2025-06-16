#add_executable(test_runner TestBasic.cpp)
#target_include_directories(test_runner PRIVATE
#                             ${MY_INCLUDE_DIR}
#                             ${MY_SRC_DIR}
#                             ${gtest_SOURCE_DIR}/googletest/include 
#                             
#)
#target_link_libraries(test_runner PRIVATE
#    project_lib
#    gtest_main
#)
#add_test(NAME MyTests COMMAND test_runner)
#include (GoogleTest)
#gtest_discover_tests(test_runner)
# Тестовый исполняемый файл
add_executable(test_runner
    ${CMAKE_CURRENT_SOURCE_DIR}/TestBasic.cpp
)
target_include_directories(test_runner PRIVATE
    ${MY_INCLUDE_DIR}
    ${gtest_SOURCE_DIR}/googletest/include  # Путь к заголовкам GTest
)
target_link_libraries(test_runner PRIVATE
    project_lib  # Линкуемся с основной библиотекой
    gtest_main   # Только для тестов
)

# Интеграция с CTest
enable_testing()
include(GoogleTest)
gtest_discover_tests(test_runner)