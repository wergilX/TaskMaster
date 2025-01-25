# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TaskMaster++")
# Указываем путь к Asio
include_directories(external/asio/include)
include_directories(external)
#add_definitions(-DASIO_STANDALONE)
add_definitions(-DCROW_USE_BOOST)
add_executable (TaskMaster++ "main.cpp" "include/models/Task.h" "src/controllers/TaskKontroller.h")

#find_package(Threads REQUIRED)
#target_link_libraries(TaskMaster++ PRIVATE Threads::Threads)


# Include sub-projects.
#add_subdirectory ("TaskMaster++")
