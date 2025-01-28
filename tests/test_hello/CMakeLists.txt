#include_directories(${GTEST_INCLUDE_DIRS})

add_executable(TestHello test_hello.cpp)

target_link_libraries(TestHello GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestHello)
