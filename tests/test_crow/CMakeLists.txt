add_executable(TestCrow test_crow.cpp)

target_include_directories(TestCrow 
PRIVATE ${Boost_INCLUDE_DIRS} 
PRIVATE ${CMAKE_SOURCE_DIR}/external
PRIVATE ${CMAKE_SOURCE_DIR}
)

target_link_libraries(TestCrow 
PRIVATE GTest::gtest_main 
PRIVATE ${Boost_LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(TestCrow)
