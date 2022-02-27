add_library(sort src/insertionSort.cpp src/bubbleSort.cpp)
target_include_directories(sort PUBLIC include)

add_executable(sort_tests uts/sortTests.cpp)
target_link_libraries(sort_tests gtest gtest_main sort)