# CMakeList.txt : CMake project for Sync, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Sync "Sync.cpp" "Sync.h")

find_package(Threads REQUIRED)
target_link_libraries(Sync PRIVATE Threads::Threads)

# TODO: Add tests and install targets if needed.
set(CMAKE_CXX_STANDART 17) 