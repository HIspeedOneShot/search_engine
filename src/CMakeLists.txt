add_library(project_lib STATIC
                ${MY_SRC_DIR}/InvertedIndex.cpp
                ${MY_SRC_DIR}/ConverterJSON.cpp
                ${MY_SRC_DIR}/SearchServer.cpp        
)

#add_executable(search_engine main.cpp
#                             ${MY_INCLUDE_DIR}/ConverterJSON.h
#                             ConverterJSON.cpp
#                             ${MY_INCLUDE_DIR}/InvertedIndex.h
#                             InvertedIndex.cpp
#                             ${MY_INCLUDE_DIR}/SearchServer.h
#                             SearchServer.cpp
#)


#FetchContent_MakeAvailable(googletest)
                             
#target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})
target_include_directories(project_lib PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(project_lib PRIVATE nlohmann_json::nlohmann_json)

add_executable(search_engine 
                ${MY_SRC_DIR}/main.cpp)

target_link_libraries(search_engine PRIVATE
                project_lib
)       
#include (GoogleTest)
#gtest_discover_tests(search_engine)