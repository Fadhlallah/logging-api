# CMakeList.txt : CMake project for logging-api, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(include)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

file(GLOB SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

file(GLOB INC "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")



# Add source to this project's executable.
add_library(liblogging  "${SRCS}" "${INC}")

enable_testing()
add_subdirectory("test")

# TODO: Add tests and install targets if needed.
