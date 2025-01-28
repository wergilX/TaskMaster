cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TaskMaster VERSION 1.0)

find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)

add_definitions(-DCROW_USE_BOOST)

add_executable(${PROJECT_NAME} "main.cpp")

target_include_directories(${PROJECT_NAME} 
PRIVATE "${CMAKE_SOURCE_DIR}"
PRIVATE "${Boost_INCLUDE_DIRS}"
PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/external"
)

target_link_libraries(${PROJECT_NAME} 
PRIVATE "${Boost_LIBRARIES}" 
PRIVATE "OpenSSL::SSL" 
PRIVATE "OpenSSL::Crypto"
#PRIVATE "GTest::GTest"
#PRIVATE "GTest::Main"
)

enable_testing()

add_subdirectory(tests)

# DEPENDENCIES
# sudo apt-get install libgtest-dev