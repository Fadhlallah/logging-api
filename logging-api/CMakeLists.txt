# CMakeList.txt : CMake project for logging-api, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(include)

file(GLOB SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

file(GLOB INC "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
message("hello     ${SRCS}")

# Add source to this project's executable.
#add_executable (logging-api "${SRCS}" "${INC}" "src/somefiles/hello.cpp")
add_library(liblogging "${SRCS}" "${INC}")

# TODO: Add tests and install targets if needed.
