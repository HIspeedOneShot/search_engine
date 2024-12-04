cmake_minimum_required(VERSION 3.5.0)
project(search_engine VERSION 0.1.0 LANGUAGES C CXX)



add_executable(search_engine main.cpp
                             ${MY_INCLUDE_DIR}/ConverterJSON.h
                             ConverterJSON.cpp)

target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

