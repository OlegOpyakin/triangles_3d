cmake_minimum_required(VERSION 3.14)

project(my_triangles)

# GoogleTest requires at least C++14
set(CMAKE_CXX_FLAGS "-std=c++20 -O2 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++20 -Wall -g -O0 -fsanitize=address -fsanitize=undefined")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_library(Lib SHARED src/main.cc)

add_executable(MAIN src/main.cc src/approx_equal.cc src/cut.cc src/func.cc src/line.cc src/plane.cc src/point.cc src/triangle.cc src/vector.cc)
add_executable(TESTS src/TESTS.cc src/approx_equal.cc src/cut.cc src/func.cc src/line.cc src/plane.cc src/point.cc src/triangle.cc src/vector.cc)

target_include_directories(TESTS PUBLIC include/)
target_include_directories(MAIN PUBLIC include/)
target_include_directories(Lib PUBLIC include/)

target_link_libraries(TESTS GTest::gtest_main Lib)

include(GoogleTest)
gtest_discover_tests(TESTS)