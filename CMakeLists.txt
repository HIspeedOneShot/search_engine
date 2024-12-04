cmake_minimum_required(VERSION 3.5.0)
project(search_engine VERSION 0.1.0 LANGUAGES C CXX)

set(JSON_BuildTest OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)
include(CTest)
enable_testing()



set(MY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)