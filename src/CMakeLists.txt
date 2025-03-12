add_executable(search_engine main.cpp
                             ${MY_INCLUDE_DIR}/ConverterJSON.h
                             ConverterJSON.cpp
                             ${MY_INCLUDE_DIR}/InvertedIndex.h
                             InvertedIndex.cpp
                             ${MY_INCLUDE_DIR}/SearchServer.h
                             SearchServer.cpp)

target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})

add_library(mylib STATIC ${MY_INCLUDE_DIR}/ConverterJSON.h
                         ConverterJSON.cpp
                         ${MY_INCLUDE_DIR}/InvertedIndex.h
                         InvertedIndex.cpp
                         ${MY_INCLUDE_DIR}/SearchServer.h
                         SearchServer.cpp)

                             
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json PRIVATE gtest_main)
include (GoogleTest)
gtest_discover_tests(search_engine)