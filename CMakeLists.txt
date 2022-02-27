cmake_minimum_required(VERSION 3.13)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(sort)

enable_testing()
add_test(sort_tests sort/sort_tests)
