cmake_minimum_required(VERSION 3.14)
project(search_engine VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0135 NEW)

set(MY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MY_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

set(JSON_BuildTest OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)



include(FetchContent)
FetchContent_Declare(
                     googletest
                     URL
                     https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
                    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)


#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(test)

include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
