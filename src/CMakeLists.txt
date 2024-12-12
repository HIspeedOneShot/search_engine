add_executable(search_engine main.cpp
                             ${MY_INCLUDE_DIR}/ConverterJSON.h
                             ConverterJSON.cpp
                             ${MY_INCLUDE_DIR}/InvertedIndex.h
                             InvertedIndex.cpp)


                             FetchContent_MakeAvailable(googletest)
                             
target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json PRIVATE gtest_main)

include (GoogleTest)
gtest_discover_tests(search_engine)